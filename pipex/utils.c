/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:46:52 by ksuh              #+#    #+#             */
/*   Updated: 2024/05/08 20:41:52 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strndup(const char *s1, size_t n);
static char	*ft_join_path(char *dir, char *cmd);
static int	ft_strichr(const char *s, int c);

char	*get_command_path(char *pathname, char **envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;
	int		move;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (ft_strdup(pathname));
	path = &envp[i][5];
	while (path && ft_strichr(path, ':') != -1)
	{
		move = ft_strichr(path, ':');
		dir = ft_strndup(path, move);
		bin = ft_join_path(dir, pathname);
		free(dir);
		if (access(bin, F_OK | X_OK) == 0)
			return (bin);
		free(bin);
		path += move + 1;
	}
	return (ft_strdup(pathname));
}

int	ft_strichr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	if (ch == '\0')
		return (i);
	return (-1);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;

	ptr = malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, n);
	ptr[n] = '\0';
	return (ptr);
}

char	*ft_join_path(char *dir, char *cmd)
{
	char	*path;
	int		i;
	int		j;

	path = malloc((ft_strlen(dir) + ft_strlen(cmd) + 2) * sizeof(char));
	if (!path)
		return (NULL);
	i = 0;
	j = 0;
	while (dir[j])
		path[i++] = dir[j++];
	path[i++] = '/';
	j = 0;
	while (cmd[j])
		path[i++] = cmd[j++];
	path[i] = '\0';
	return (path);
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
