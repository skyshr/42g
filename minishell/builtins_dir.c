/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:46:23 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/27 21:02:29 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_pwd(char **args, t_env *head);

int	ft_cd(char **args, t_env *head)
{
	char	*pwd;
	char	*oldpwd;

	oldpwd = getcwd(NULL, 1024);
	if (args[1] && args[2])
	{
		ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
		return (free(oldpwd), FAIL);
	}
	pwd = ft_get_pwd(args, head);
	if (pwd == NULL)
		return (free(oldpwd), FAIL);
	if (pwd[0] != '\0' && chdir(pwd) != 0)
	{
		ft_putstr_fd("bash: cd: ", STDERR_FILENO);
		ft_putstr_fd(pwd, STDERR_FILENO);
		(ft_putstr_fd(": ", STDERR_FILENO), perror(""));
		return (free(oldpwd), FAIL);
	}
	pwd = getcwd(NULL, 1024);
	edit_env_pwd("OLDPWD", oldpwd, head);
	edit_env_pwd("PWD", pwd, head);
	if (args[1] && args[1][0] == '-' && args[1][1] == '\0')
		printf("%s\n", pwd);
	return (free(oldpwd), free(pwd), SUCCESS);
}

int	ft_pwd(void)
{
	char	*buf;
	char	*pwd;

	buf = NULL;
	pwd = getcwd(buf, 1024);
	if (pwd == NULL)
	{
		ft_putendl_fd("bash: pwd: error", STDERR_FILENO);
		return (free(pwd), FAIL);
	}
	else
		printf("%s\n", pwd);
	return (free(pwd), SUCCESS);
}

int	ft_exit(t_minishell *ms, char **args)
{
	ms->isexit = 1;
	if (args[1] == NULL)
		return (ms->exit);
	if (is_valid_exit(args[1]) == FAIL)
		return (2);
	if (args[2])
	{
		ms->isexit = 0;
		ft_putendl_fd("bash: exit: too many arguments", STDERR_FILENO);
		return (FAIL);
	}
	return (ft_atoi(args[1]) % 256);
}

char	*ft_get_pwd(char **args, t_env *head)
{
	char	*pwd;

	if (args[1] == NULL)
	{
		pwd = env_get_value("HOME", head);
		if (pwd == NULL)
		{
			ft_putendl_fd("bash: cd: HOME not set", STDERR_FILENO);
			return (NULL);
		}
	}
	else if (args[1][0] == '-' && args[1][1] == '\0')
		pwd = env_get_value("OLDPWD", head);
	else
		pwd = args[1];
	if (pwd == NULL)
	{
		if (args[1][0] == '-' && args[1][1] == '\0')
			ft_putendl_fd("bash: cd: OLDPWD not set", STDERR_FILENO);
		else
			ft_putendl_fd("bash: cd: get path error", STDERR_FILENO);
		return (NULL);
	}
	change_env_status(head);
	return (pwd);
}

int	isfile(const char *name)
{
	DIR	*directory;

	directory = opendir(name);
	if (directory != NULL)
	{
		closedir(directory);
		return (0);
	}
	if (errno == ENOTDIR)
		return (1);
	return (-1);
}
