/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:00:19 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 19:56:06 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	do_sigint_cat1(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	do_sigint_cat(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit_status = SIGINT;
}

void	do_sigquit_cat(int signum)
{
	(void)signum;
	ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	g_exit_status = SIGQUIT;
}

void	do_sigint_heredoc(int signum)
{
	(void)signum;
	ft_putstr_fd("^C\n", STDERR_FILENO);
	rl_replace_line("", 0);
	exit(2);
}

void	do_sigint(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = SIGINT;
}
