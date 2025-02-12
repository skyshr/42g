/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:49:10 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 19:57:30 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	j = 1;
	len = get_args_len(args);
	if (len > 1)
	{
		if (ft_strcmp(args[1], "-n") == 0)
		{
			i++;
			j++;
		}
		while (i < len - 1)
			printf("%s ", args[i++]);
		if (i == len - 1)
			printf("%s", args[i]);
	}
	if (j == 1)
		printf("\n");
	return (SUCCESS);
}

int	ft_export(char **args, t_env **head)
{
	int	i;
	int	status;

	status = SUCCESS;
	if (args[1] == NULL)
		print_export(*head);
	else
	{
		i = 1;
		while (args[i])
		{
			status = change_export(head, args[i]);
			i++;
		}
	}
	return (status);
}

int	ft_unset(char **args, t_env **head)
{
	t_env	*env;
	int		i;

	i = 1;
	while (args[i])
	{
		if (ft_strcmp("PWD", args[i]) == 0 || \
			ft_strcmp("OLDPWD", args[i]) == 0)
		{
			env = ft_lstfind_node(*head, args[i]);
			if (env)
				env->status = 0;
		}
		else
			unset_env(args[i], head);
		i++;
	}
	return (SUCCESS);
}

int	ft_env(char **args, t_env *head)
{
	t_env	*tmp;

	if (args[1])
		return (FAIL);
	tmp = head;
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp -> next;
	}
	return (SUCCESS);
}

int	split_env(char *str, char **name, char **value)
{
	int	i;
	int	j;

	i = 0;
	if (ft_isquote(str[i]) || ft_isdigit(str[i]))
		return (FAIL);
	while (str[i] && str[i] != '=' && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if ((str[i] && str[i] != '=') || i == 0)
		return (FAIL);
	*name = ft_substr(str, 0, i);
	if ((*name) == NULL)
		error(4);
	*value = NULL;
	if (str[i] == '\0')
		return (SUCCESS);
	j = 0;
	i++;
	while (str[j + i])
		j++;
	(*value) = ft_substr(str, i, j);
	if ((*value) == NULL)
		error(4);
	return (SUCCESS);
}
