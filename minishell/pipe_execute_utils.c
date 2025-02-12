/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:19:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 21:04:00 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	get_waitpid_status(t_pipex *pipex, int i)
{
	if (i == 0)
	{
		wait(&pipex->exit);
		pipex->exit = WEXITSTATUS(pipex->exit);
		pipex->oper_status = pipex->exit;
	}
	else
	{
		wait(&pipex->exit);
		pipex->exit = WEXITSTATUS(pipex->exit);
	}
}

int	iscmd_cat(t_pipex *pipex, char **args)
{
	int	len;

	if (pipex->dupin > 0)
		return (0);
	len = ft_strlen(*args);
	if (len == 0)
		return (0);
	while (len && (*args)[len] != '/')
		len--;
	if ((*args)[len] == '/')
		len++;
	return (!ft_strcmp(*args + len, "cat") && args[1] == NULL);
}

int	is_interactive_mode(t_pipex *pipex, char **args)
{
	int	len;

	if (pipex->dupin > 0)
		return (0);
	if (iscmd_cat(pipex, args))
		return (1);
	len = ft_strlen(*args);
	if (len == 0)
		return (0);
	while (len && (*args)[len] != '/')
		len--;
	if ((*args)[len] == '/')
		len++;
	if (!ft_strcmp(*args + len, "grep") && args[1])
		return (1);
	if (!ft_strcmp(*args + len, "wc") && (args[1] == NULL || args[1][0] == '-'))
		return (1);
	if (!ft_strcmp(*args + len, "sleep"))
		return (1);
	return (0);
}

void	redirect_ppid(t_pipex *pipex, char **args, int fd)
{
	if (iscmd_cat(pipex, args))
		dup2(pipex->save_fdin, STDIN_FILENO);
	else
		dup2(fd, STDIN_FILENO);
	if (pipex->is_heredoc || !ft_strcmp(*args, EXEC))
		get_waitpid_status(pipex, 1);
}

void	redirect_pid(t_pipex *pipex, char **args, int fd)
{
	if (pipex->dupout < 0)
		dup2(fd, STDOUT_FILENO);
	else if (iscmd_cat(pipex, args))
		dup2(pipex->save_fdout, STDOUT_FILENO);
}
