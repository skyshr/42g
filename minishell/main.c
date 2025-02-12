/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:44:09 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 20:58:56 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	make_loop(t_minishell *ms);

int	g_exit_status;

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*ms;
	int			exit;

	(void)argv;
	if (argc != 1)
		error(120);
	ms = init_minishell(envp);
	make_loop(ms);
	exit = ms->exit;
	ft_putendl_fd("exit", STDOUT_FILENO);
	clear_history();
	free_minishell(&ms);
	return (exit);
}

void	make_loop(t_minishell *ms)
{
	char	*str;

	while (!ms->isexit)
	{
		set_signal();
		str = readline("user$ ");
		if (str == NULL)
			break ;
		if (*str != '\0')
			add_history(str);
		if (g_exit_status == SIGINT)
			ms->exit = SIGINTERR;
		else if (g_exit_status == SIGQUIT)
			ms->exit = SIGQUITERR;
		g_exit_status = SUCCESS;
		ms->exit = handle_operations(str, ms);
		free(str);
		dup2(ms->pipex->save_fdin, STDIN_FILENO);
		dup2(ms->pipex->save_fdout, STDOUT_FILENO);
	}
}
