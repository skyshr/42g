/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:14:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 18:59:15 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	change_curtree(t_minishell *ms)
{
	int	new_type;
	int	temp;

	if (ms->pipex->oper_status == -1)
		return ;
	if ((ms->node_type == NODE_OR && ms->pipex->oper_status == SUCCESS) \
		|| (ms->node_type == NODE_AND && ms->pipex->oper_status != SUCCESS))
	{
		new_type = NODE_AND + (ms->node_type == NODE_AND);
		temp = ms->cur_treenode->start_bracket;
		while (ms->cur_treenode)
		{
			if (ms->cur_treenode->start_bracket == temp \
				&& ms->cur_treenode->type == (t_nodetype)new_type)
			{
				ms->node_type = ms->cur_treenode->type;
				ms->cur_treenode = ms->cur_treenode->right;
				break ;
			}
			ms->cur_treenode = ms->cur_treenode->right;
		}
	}
	else
		ms->cur_treenode = ms->cur_treenode->right;
}

int	is_nodetype_and_or(int type)
{
	return (type == NODE_OR || type == NODE_AND);
}

void	change_status_on_rdt_fail(t_minishell *ms)
{
	if (ms->cur_treenode->type == NODE_OR)
		ms->pipex->oper_status = SUCCESS;
	else if (ms->cur_treenode->type == NODE_AND)
		ms->pipex->oper_status = FAIL;
	else if (ms->cur_treenode->type != NODE_PIPE)
		ms->pipex->exit = FAIL;
}

void	parent_wait(t_minishell *ms, char **args)
{
	if (!ft_strcmp(*args, EXEC))
		get_waitpid_status(ms->pipex, 1);
	else
		get_waitpid_status(ms->pipex, 0);
}

int	process_cmd(t_minishell *ms)
{
	while (ms->cur_treenode)
	{
		if (is_nodetype_and_or(ms->cur_treenode->type) \
			&& is_nodetype_and_or(ms->cur_treenode->left->type))
			return (handle_multi_cmd1(ms->cur_treenode, ms));
		preprocess(ms);
		if (is_nodetype_and_or(ms->cur_treenode->type))
		{
			ms->node_type = ms->cur_treenode->type;
			wait_child(ms->pipex);
			ms->root = ms->cur_treenode;
			return (handle_multi_cmd(ms, ms->pipex->oper_status));
		}
		if (g_exit_status)
			break ;
		else if (ms->cur_treenode->type != NODE_PIPE)
			break ;
		ms->cur_treenode = ms->cur_treenode->right;
	}
	return (wait_child(ms->pipex));
}
