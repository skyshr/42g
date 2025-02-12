/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:41:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/27 13:28:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_data(char *name, char *value);

int	is_builtins(char *cmd)
{
	if (cmd == NULL)
		return (8);
	if (!ft_strcmp("env", cmd))
		return (1);
	else if (!ft_strcmp("export", cmd))
		return (2);
	else if (!ft_strcmp("unset", cmd))
		return (3);
	else if (!ft_strcmp("cd", cmd))
		return (4);
	else if (!ft_strcmp("pwd", cmd))
		return (5);
	else if (!ft_strcmp("echo", cmd))
		return (6);
	else if (!ft_strcmp("exit", cmd))
		return (7);
	return (0);
}

int	exec_builtins(t_minishell *ms, char **cmds)
{
	if (ms->exe_num == 1)
		return (ft_env(cmds, ms->head));
	else if (ms->exe_num == 2)
		return (ft_export(cmds, &ms->head));
	else if (ms->exe_num == 3)
		return (ft_unset(cmds, &ms->head));
	else if (ms->exe_num == 4)
		return (ft_cd(cmds, ms->head));
	else if (ms->exe_num == 5)
		return (ft_pwd());
	else if (ms->exe_num == 6)
		return (ft_echo(cmds));
	else if (ms->exe_num == 7)
		return (ft_exit(ms, cmds));
	return (SUCCESS);
}

char	**get_env(t_env *head)
{
	t_env	*tmp;
	char	**res;
	int		len;
	int		i;

	len = get_env_len(head);
	res = (char **)malloc((len + 1) * sizeof(char *));
	if (res == NULL)
		error(4);
	tmp = head;
	i = 0;
	while (tmp)
	{
		res[i] = get_env_data(tmp->name, tmp->value);
		if (res[i] == NULL)
			error(4);
		tmp = tmp -> next;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	*get_env_data(char *name, char *value)
{
	char	*join;
	int		i;
	int		j;

	join = (char *)malloc((ft_strlen(name) + ft_strlen(value) \
							+ 1 + (value != NULL)) * sizeof(char));
	if (join == NULL)
		error(4);
	i = 0;
	j = 0;
	while (name[j])
		join[i++] = name[j++];
	if (!value)
	{
		join[i] = '\0';
		return (join);
	}
	join[i++] = '=';
	j = 0;
	while (value[j])
		join[i++] = value[j++];
	join[i] = '\0';
	return (join);
}
