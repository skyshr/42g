/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:19:58 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/24 16:22:56 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5)
		error(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc != 6)
			error(5);
		heredoc(&pipex, argv, envp);
		return (0);
	}
	handle_file_errors(&pipex, argv[1], argv[argc - 1]);
	pipex.dupin = dup2(pipex.fdin, STDIN_FILENO);
	pipex.dupout = dup2(pipex.fdout, STDOUT_FILENO);
	redirect(argv[2], envp, pipex.dupin);
	i = 3;
	while (i < argc - 2)
		redirect(argv[i++], envp, 0);
	redirect_end(&pipex, argv[argc - 2], argv[argc - 1], envp);
	wait_child(&pipex, argc - 2);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (0);
}

void	redirect(char *cmd, char **envp, int n)
{
	pid_t	pid;
	int		fd[2];

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
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (n != -1)
			execute(cmd, envp);
		exit(1);
	}
}

void	execute(char *cmd, char **envp)
{
	char	**sp;
	char	*path;

	sp = split(cmd, ' ');
	if (!sp)
		error(4);
	if (ft_strchr(sp[0], '/'))
		path = sp[0];
	else
		path = get_command_path(sp[0], envp);
	if (execve(path, sp, envp) == -1)
		free_data(sp, path, 6);
}

void	free_data(char **sp, char *path, int error_num)
{
	int	i;

	print_file_error("zsh: command not found: ", sp[0]);
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	free(path);
	error(error_num);
}

void	redirect_end(t_pipex *pipex, char *cmd, char *outfile, char **envp)
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
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		if (pipex->dupout != -1)
			execute(cmd, envp);
		else
			print_file_error("zsh: permission denied: ", outfile);
		exit(1);
	}
}
