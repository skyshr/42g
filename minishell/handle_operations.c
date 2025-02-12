/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:07:27 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 19:00:10 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_cmd(t_minishell *ms);
static int	redirect_single_cmd(t_minishell *ms);
static void	free_strs(char **str1, char **str2, char **str3);

int	handle_operations(char *str, t_minishell *ms)
{
	char	*trans_str;
	char	*astk_str;
	char	*ordered_str;
	int		exit;

	free(ms->exit_str);
	ms->exit_str = ft_itoa(ms->exit);
	if (ms->exit_str == NULL)
		error(4);
	trans_str = init_cmds_rdts(str, ms);
	if (!is_valid_parenthesis(trans_str))
		return (free(trans_str), FAIL);
	if (trans_str[0] == '\0')
		return (ms->exit);
	astk_str = translate_asterisk(trans_str);
	ordered_str = order_str(astk_str);
	ms->root = do_parse_input(ms, ordered_str);
	free_strs(&trans_str, &astk_str, &ordered_str);
	if (ms->root == NULL)
		return (ms->exit);
	ms->root_treenode = ms->root;
	ms->node_type = NODE_PIPE;
	exit = handle_cmd(ms);
	return (free_tree(ms->tmp_root), exit);
}

int	handle_cmd(t_minishell *ms)
{
	ms->exe_num = is_builtins(ms->root->command);
	if (ms->treenode_num == 1 && ms->exe_num)
		return (redirect_single_cmd(ms));
	else
		return (handle_multi_cmd1(ms->root, ms));
}

int	redirect_single_cmd(t_minishell *ms)
{
	int	exit;

	reset_pipex(ms->pipex);
	interpret_ios(ms, ms->root);
	if (ms->pipex->status == 0)
	{
		if (ms->pipex->dupin > 0)
			close(ms->pipex->dupin);
		if (ms->pipex->dupout > 0)
			close(ms->pipex->dupout);
		return (FAIL);
	}
	exit = exec_builtins(ms, ms->command_tree->arguments);
	if (ms->pipex->dupin > 0)
		close(ms->pipex->dupin);
	if (ms->pipex->dupout > 0)
		close(ms->pipex->dupout);
	return (exit);
}

void	free_strs(char **str1, char **str2, char **str3)
{
	free(*str1);
	free(*str2);
	free(*str3);
	*str1 = NULL;
	*str2 = NULL;
	*str3 = NULL;
}
