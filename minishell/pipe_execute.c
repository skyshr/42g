/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:35:07 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 21:14:02 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_command_path(char *pathname, t_env *head);
static char	*ft_strndup(const char *s1, size_t n);
static char	*ft_join_path(char *dir, char *arg);
static int	ft_strichr(const char *s, int c);

void	execute(t_minishell *ms, char **args)
{
	char	*path;
	char	**env;
	int		exit_code;

	if ((*args) == NULL)
		(free_tree(ms->tmp_root), free_minishell(&ms), exit(0));
	ms->exe_num = is_builtins(*args);
	if (ms->exe_num)
	{
		exit_code = exec_builtins(ms, args);
		(free_tree(ms->tmp_root), free_minishell(&ms), exit(exit_code));
	}
	if ((*args)[0] == '\0')
	{
		ft_putendl_fd(": command not found", STDERR_FILENO);
		(free_tree(ms->tmp_root), free_minishell(&ms), exit(127));
	}
	if (ft_strchr(*args, '/'))
		path = ft_strdup(*args);
	else
		path = get_command_path(*args, ms->head);
	env = get_env(ms->head);
	if (execve(path, args, env) == -1)
		(free_args(env), execve_error(path, ms));
}

char	*get_command_path(char *pathname, t_env *head)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		move;

	path = env_get_value("PATH", head);
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
		error(4);
	ft_memcpy(ptr, s1, n);
	ptr[n] = '\0';
	return (ptr);
}

char	*ft_join_path(char *dir, char *arg)
{
	char	*path;
	int		i;
	int		j;

	path = malloc((ft_strlen(dir) + ft_strlen(arg) + 2) * sizeof(char));
	if (!path)
		error(4);
	i = 0;
	j = 0;
	while (dir[j])
		path[i++] = dir[j++];
	path[i++] = '/';
	j = 0;
	while (arg[j])
		path[i++] = arg[j++];
	path[i] = '\0';
	return (path);
}
