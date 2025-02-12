/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:53:14 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 20:52:35 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_pipex(t_pipex **pipex);
static void	init_linked(t_env **head, char **envp);

t_minishell	*init_minishell(char **envp)
{
	t_minishell	*minishell;

	minishell = malloc(sizeof(t_minishell));
	if (minishell == NULL)
		error(4);
	init_pipex(&minishell->pipex);
	init_linked(&minishell->head, envp);
	minishell->cur_treenode = NULL;
	minishell->node_type = NODE_PIPE;
	minishell->exe_num = 0;
	minishell->exit = 0;
	minishell->exit_str = NULL;
	minishell->isexit = 0;
	return (minishell);
}

void	init_pipex(t_pipex **pipex)
{
	*pipex = malloc(sizeof(t_pipex));
	if (*pipex == NULL)
		error(4);
	(*pipex)->dupin = -2;
	(*pipex)->dupout = -2;
	(*pipex)->save_fdin = dup(STDIN_FILENO);
	(*pipex)->save_fdout = dup(STDOUT_FILENO);
	(*pipex)->status = 1;
	(*pipex)->child_count = 0;
	(*pipex)->exit = 0;
	(*pipex)->oper_status = -1;
	(*pipex)->is_pipe = 1;
	(*pipex)->is_heredoc = 0;
	if ((*pipex)->save_fdin == -1 || (*pipex)->save_fdout == -1)
		error(5);
}

void	init_linked(t_env **head, char **envp)
{
	t_env	*env;
	char	*name;
	char	*value;
	int		i;

	i = -1;
	*head = NULL;
	while (envp[++i])
	{
		if (split_env(envp[i], &name, &value) == FAIL)
			error(4);
		env = ft_lstnew(name, value);
		if (env == NULL)
			error(4);
		if (ft_lstadd_back(head, env) == FAIL)
			error(4);
	}
}

void	free_minishell(t_minishell **minishell)
{
	t_minishell	*tmp;

	tmp = *minishell;
	close(tmp->pipex->save_fdin);
	close(tmp->pipex->save_fdout);
	free(tmp->pipex);
	ft_lstclear(&((*minishell)->head));
	free(tmp->exit_str);
	free(tmp);
	*minishell = NULL;
}
