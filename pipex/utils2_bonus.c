/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:58:37 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/24 16:21:17 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_heredoc_input(int fd, char *limiter);
static void	heredoc_redirect(t_pipex *pipex, char **argv);

void	heredoc(t_pipex *pipex, char **argv, char **envp)
{
	char	*outfile;

	outfile = argv[5];
	heredoc_redirect(pipex, argv);
	pipex->fdout = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	pipex->dupout = dup2(pipex->fdout, STDOUT_FILENO);
	redirect(argv[3], envp, pipex->dupin);
	redirect_end(pipex, argv[4], argv[5], envp);
	wait_child(pipex, 2);
}

void	heredoc_redirect(t_pipex *pipex, char **argv)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		error(2);
	pid = fork();
	if (pid == -1)
		error(3);
	if (pid)
	{
		pipex->fdin = fd[0];
		pipex->dupin = fd[0];
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		waitpid(-1, NULL, 0);
	}
	else
	{
		close(fd[0]);
		get_heredoc_input(fd[1], argv[2]);
		close(fd[1]);
		exit(1);
	}
}

void	get_heredoc_input(int fd, char *limiter)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 0);
		line = get_next_line(0);
		if (!line || !strcmp(line, limiter))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
}
