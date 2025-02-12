/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:16:54 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 20:53:57 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_process_wait(t_minishell *ms)
{
	if (ms->pipex->is_heredoc)
		return (1);
	if (!ft_strcmp(ms->command_tree->command, EXEC))
		return (1);
	if (is_nodetype_and_or(ms->cur_treenode->type))
		return (1);
	if (!ms->pipex->status)
		return (1);
	if (ms->cur_treenode->type != NODE_PIPE)
		return (1);
	return (0);
}

void	execute_now(t_minishell *ms)
{
	ms->pipex->is_pipe = 0;
	ms->pipex->oper_status = exec_builtins(ms, ms->command_tree->arguments);
	ms->pipex->exit = ms->pipex->oper_status;
	dup2(ms->pipex->save_fdin, STDIN_FILENO);
	dup2(ms->pipex->save_fdout, STDOUT_FILENO);
}

void	set_pipe_interactive_signal(void)
{
	set_terminal_print_on();
	signal(SIGINT, do_sigint_cat1);
	signal(SIGQUIT, do_sigint_cat1);
}
