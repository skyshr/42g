/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_oper_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:49:47 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/03 14:47:10 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	edit_env_pwd(char *path, char *pwd, t_env *head)
{
	t_env	*tmp;
	char	*pwd_value;

	if (!ft_strcmp(path, "OLDPWD"))
	{
		tmp = ft_lstfind_node(head, "OLDPWD");
		if (tmp == NULL || !tmp->status)
			return (FAIL);
	}
	pwd_value = ft_strdup(pwd);
	if (!pwd_value)
		return (FAIL);
	tmp = head;
	while (tmp)
	{
		if (!ft_strcmp(path, tmp->name))
		{
			free(tmp->value);
			tmp->status = 1;
			tmp->value = pwd_value;
			break ;
		}
		tmp = tmp -> next;
	}
	return (SUCCESS);
}

int	is_valid_exit(char *args)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (args[i])
	{
		cnt += ft_issign(args[i]);
		if (cnt > 1 || (!ft_issign(args[i]) && !ft_isdigit(args[i])))
		{
			print_stderr("bash: exit: ", ": numeric argument required", args);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int	get_env_len(t_env *head)
{
	t_env	*tmp;
	int		len;

	tmp = head;
	len = 0;
	while (tmp)
	{
		if (tmp->value != NULL)
			len++;
		tmp = tmp->next;
	}
	return (len);
}
