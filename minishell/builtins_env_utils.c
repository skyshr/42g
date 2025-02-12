/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:51:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/27 21:03:51 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get_value(char *name, t_env *head)
{
	t_env	*tmp;

	tmp = ft_lstfind_node(head, name);
	if (tmp == NULL)
		return (NULL);
	if (tmp->status)
		return (tmp->value);
	return (NULL);
}

void	change_env_status(t_env *head)
{
	t_env	*tmp;
	t_env	*tmp1;

	tmp = ft_lstfind_node(head, "OLDPWD");
	tmp1 = ft_lstfind_node(head, "PWD");
	if (tmp == NULL || tmp1 == NULL)
		return ;
	if (!tmp1->status)
	{
		tmp->status = 0;
		tmp1->status = 1;
	}
	else if (tmp1->status)
		tmp->status = 1;
}

void	print_export(t_env *head)
{
	if (!head)
		return ;
	printf("declare -x %s", head->name);
	if (head->value)
		printf("=\"%s\"", head->value);
	printf("\n");
	print_export(head->next);
}

int	change_export(t_env **head, char *arg)
{
	t_env	*env;
	char	*name;
	char	*value;

	name = NULL;
	value = NULL;
	if (split_env(arg, &name, &value) == FAIL)
	{
		print_stderr("bash: export: `", "': not a valid identifier", arg);
		return (FAIL);
	}
	env = ft_lstfind_node(*head, name);
	if (env)
	{
		free(name);
		if (value == NULL)
			return (SUCCESS);
		free(env->value);
		env->value = value;
		env->status = 1;
	}
	else
		ft_lstadd_back(head, ft_lstnew(name, value));
	return (SUCCESS);
}

void	unset_env(char *name, t_env **head)
{
	t_env	*prev_tmp;
	t_env	*tmp;

	prev_tmp = NULL;
	tmp = *head;
	while (tmp)
	{	
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (prev_tmp == NULL)
				*head = tmp->next;
			else
				prev_tmp -> next = tmp -> next;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			return ;
		}
		else
		{
			prev_tmp = tmp;
			tmp = tmp->next;
		}
	}
}
