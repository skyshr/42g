/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:40:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 20:53:09 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_redirect(t_pipex *pipex, char *filename);
static void	get_heredoc_input(t_pipex *pipex, char *filename);

extern int	g_exit_status;

void	here_doc(t_pipex *pipex, char *filename)
{
	if (pipex->exit)
		return ;
	pipex->is_heredoc = 1;
	if (pipex->dupin > 0)
	{
		close(pipex->dupin);
		pipex->dupin = -2;
	}
	heredoc_redirect(pipex, filename);
}

void	heredoc_redirect(t_pipex *pipex, char *filename)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error(2);
	pid = fork();
	if (pid == -1)
		error(3);
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		get_waitpid_status(pipex, 1);
	}
	else
	{
		signal(SIGINT, do_sigint_heredoc);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		get_heredoc_input(pipex, filename);
		close(fd[1]);
		exit(g_exit_status);
	}
}

void	get_heredoc_input(t_pipex *pipex, char *filename)
{
	char	*line;

	dup2(pipex->save_fdin, STDIN_FILENO);
	while (1)
	{
		ft_putstr_fd("> ", STDIN_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || !ft_strcmp(line, filename))
		{
			if (line == NULL)
			{
				ft_putstr_fd("bash: warning: here-document", STDERR_FILENO);
				print_stderr(" delimited by end-of-file (wanted `", \
							"')", filename);
			}
			free(line);
			break ;
		}
		ft_putendl_fd(line, STDOUT_FILENO);
		free(line);
	}
}
