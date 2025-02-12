/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_interpret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:29:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/26 21:40:06 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_file_access(t_pipex *pipex, char *file_name, int num);
static int	is_accessable(t_pipex *pipex, char *file, int num);

void	interpret_ios(t_minishell *ms, t_treenode *root_node)
{
	if (!root_node)
		return ;
	interpret_ios(ms, root_node->left);
	if (root_node->type == NODE_REDIR_IN)
		check_file_access(ms->pipex, root_node->right->command, 0);
	else if (root_node->type == NODE_REDIR_DOUBLE_IN)
		here_doc(ms->pipex, root_node->right->command);
	else if (root_node->type == NODE_REDIR_OUT)
		check_file_access(ms->pipex, root_node->right->command, 1);
	else if (root_node->type == NODE_REDIR_DOUBLE_OUT)
		check_file_access(ms->pipex, root_node->right->command, 2);
	else if (root_node->type == NODE_COMMAND)
		ms->command_tree = root_node;
}

void	check_file_access(t_pipex *pipex, char *filename, int num)
{
	if (pipex->status == 0)
		return ;
	if (is_accessable(pipex, filename, num) == FAIL)
		return ;
	dup_file(pipex, filename, num);
	if (pipex->dupin == -1 || pipex->dupout == -1)
		io_error(pipex, filename, 3);
}

int	is_accessable(t_pipex *pipex, char *file, int num)
{
	if (num == 0)
	{
		if (access(file, F_OK))
			return (io_error(pipex, file, 1));
		if (access(file, R_OK))
			return (io_error(pipex, file, 2));
		if (pipex->dupin > 0)
			close(pipex->dupin);
	}
	else
	{
		if (!access(file, F_OK) && access(file, W_OK))
			return (io_error(pipex, file, 2));
		if (pipex->dupout > 0)
			close(pipex->dupout);
	}
	return (SUCCESS);
}
