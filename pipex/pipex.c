/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:28:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/24 16:27:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_file_errors(t_pipex *pipex, char *infile, char *outfile);
static void	redirect(t_pipex *pipex, char *cmd, char **envp);
static void	free_data(char **sp, char *path, int error_num);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		count;
	int		status;

	if (argc != 5)
		error(1);
	handle_file_errors(&pipex, argv[1], argv[4]);
	redirect(&pipex, argv[2], envp);
	redirect_end(&pipex, argv[argc - 2], argv[argc - 1], envp);
	count = 0;
	while (count < 2)
	{
		if (wait(&status) == -1)
			break ;
		count++;
	}
	if (pipex.fdin > 0)
		close(pipex.fdin);
	if (pipex.fdout > 0)
		close(pipex.fdout);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (0);
}

void	redirect(t_pipex *pipex, char *cmd, char **envp)
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
		if (pipex->dupin != -1)
			execute(cmd, envp);
		exit(1);
	}
}

void	handle_file_errors(t_pipex *pipex, char *infile, char *outfile)
{
	pipex->fdin = access(infile, F_OK);
	if (pipex->fdin == -1)
		print_file_error("zsh: no such file or directory: ", infile);
	else
	{
		pipex->fdin = open(infile, O_RDONLY);
		if (pipex->fdin == -1)
			print_file_error("zsh: permission denied: ", infile);
	}
	pipex->fdout = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipex->dupin = dup2(pipex->fdin, STDIN_FILENO);
	pipex->dupout = dup2(pipex->fdout, STDOUT_FILENO);
}

void	execute(char *cmd, char **envp)
{
	char	**sp;
	char	*path;

	sp = split(cmd, ' ');
	if (!sp)
		error(5);
	if (ft_strchr(sp[0], '/'))
		path = sp[0];
	else
		path = get_command_path(sp[0], envp);
	if (execve(path, sp, envp) == -1)
		free_data(sp, path, 5);
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
