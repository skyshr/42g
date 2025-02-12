/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:04:31 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 21:04:36 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_pipe(t_minishell *ms, char **ars);
static void	redirect_pipe_end(t_minishell *ms, char **ars);

extern int	g_exit_status;

int	handle_multi_cmd(t_minishell *ms, int status)
{
	if (status == SIGINTERR)
		return (SIGINTERR);
	g_exit_status = SUCCESS;
	set_signal_fork();
	set_terminal_print_off();
	ms->pipex->oper_status = status;
	ms->cur_treenode = ms->root;
	change_curtree(ms);
	ms->pipex->child_count = 0;
	return (process_cmd(ms));
}

void	preprocess(t_minishell *ms)
{
	reset_pipex(ms->pipex);
	interpret_ios(ms, ms->cur_treenode);
	if (ms->pipex->exit)
		ms->pipex->status = 0;
	if (is_nodetype_and_or(ms->cur_treenode->type))
		ms->node_type = ms->cur_treenode->type;
	ms->exe_num = is_builtins(ms->command_tree->command);
	if (!is_process_wait(ms))
		ms->pipex->child_count++;
	if (!ms->pipex->status)
		change_status_on_rdt_fail(ms);
	else if (ms->cur_treenode->type == NODE_PIPE)
		redirect_pipe(ms, ms->command_tree->arguments);
	else if (ms->exe_num && is_nodetype_and_or(ms->node_type))
		execute_now(ms);
	else
		redirect_pipe_end(ms, ms->command_tree->arguments);
	if (ms->pipex->dupin > 0)
		close(ms->pipex->dupin);
	if (ms->pipex->dupout > 0)
		close(ms->pipex->dupout);
}

void	redirect_pipe(t_minishell *ms, char **args)
{
	pid_t	pid;
	int		fd[2];

	if (is_interactive_mode(ms->pipex, args))
		set_pipe_interactive_signal();
	if (pipe(fd) == -1)
		error(2);
	pid = fork();
	if (pid == -1)
		error(3);
	if (pid)
	{
		close(fd[1]);
		redirect_ppid(ms->pipex, args, fd[0]);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		redirect_pid(ms->pipex, args, fd[1]);
		close(fd[1]);
		execute(ms, args);
	}
}

void	redirect_pipe_end(t_minishell *ms, char **args)
{
	pid_t	pid;
	int		fd[2];

	if (is_interactive_mode(ms->pipex, args))
		(set_terminal_print_on(), set_signal_interactive());
	if (pipe(fd) == -1)
		error(2);
	pid = fork();
	if (pid == -1)
		error(3);
	if (pid)
	{
		close(fd[0]);
		close(fd[1]);
		parent_wait(ms, args);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		if (ms->pipex->dupout < 0)
			dup2(ms->pipex->save_fdout, STDOUT_FILENO);
		execute(ms, args);
	}
}

int	wait_child(t_pipex *pipex)
{
	int	exit;
	int	status;
	int	count;

	exit = 0;
	count = 0;
	while (count < pipex->child_count)
	{
		if (wait(&status) == -1)
			return (FAIL);
		exit = WEXITSTATUS(status);
		count++;
	}
	if (pipex->exit)
		return (pipex->exit);
	if (g_exit_status == SIGINT)
		return (SIGINTERR);
	else if (g_exit_status == SIGQUIT)
		return (SIGQUITERR);
	return (exit);
}
