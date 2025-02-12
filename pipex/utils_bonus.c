/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:53:52 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/24 16:18:59 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	wait_child(t_pipex *pipex, int child_count)
{
	int	status;
	int	count;

	count = 0;
	while (count < child_count)
	{
		if (wait(&status) == -1)
			break ;
		count++;
	}
	if (pipex->fdin > 0)
		close(pipex->fdin);
	if (pipex->fdout > 0)
		close(pipex->fdout);
}
