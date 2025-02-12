/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:37:11 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 18:23:10 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_stderr(char *str1, char *str2, char *arg)
{
	ft_putstr_fd(str1, STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(str2, STDERR_FILENO);
}

void	error(int error_num)
{
	if (error_num == 2)
		ft_putendl_fd("pipe() value returned -1", STDERR_FILENO);
	else if (error_num == 3)
		ft_putendl_fd("fork() value returned -1", STDERR_FILENO);
	else if (error_num == 4)
		ft_putendl_fd("split error", STDERR_FILENO);
	else if (error_num == 5)
		ft_putendl_fd("dup error", STDERR_FILENO);
	else if (error_num == 5)
		ft_putendl_fd("opendir error", STDERR_FILENO);
	else if (error_num == 120)
		ft_putendl_fd("wrong input: usage: ./minishell", STDERR_FILENO);
	else if (error_num == 127)
		ft_putendl_fd(": command not found", STDERR_FILENO);
	exit(error_num);
}

void	execve_error(char *path, t_minishell *ms)
{
	ft_putstr_fd(path, STDERR_FILENO);
	free_tree(ms->tmp_root);
	free_minishell(&ms);
	if (ft_strncmp(path, "./", 2) && ft_strncmp(path, "/", 1))
		(free(path), error(127));
	if (access(path, F_OK) == -1)
	{
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		(free(path), exit(127));
	}
	if (isfile(path) == 0)
	{
		ft_putendl_fd(": Is a directory", STDERR_FILENO);
		(free(path), exit(126));
	}
	if (access(path, X_OK) == -1)
	{
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
		(free(path), exit(126));
	}
	free(path);
	error(127);
}

void	close_fd_error(t_minishell *ms, int errnum)
{
	if (ms->pipex->dupin > 0)
		close(ms->pipex->dupin);
	if (ms->pipex->dupout > 0)
		close(ms->pipex->dupout);
	error(errnum);
}
