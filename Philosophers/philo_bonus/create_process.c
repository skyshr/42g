/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:14:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 12:44:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	child_do(t_philo *philo);
static void	parent_do(t_philo *philo);
static void	clean_process(t_philo *philo, pid_t child_pid);
static void	kill_process(t_philo *philo, int index);

void	make_process(t_philo *philo)
{
	long long	time;
	int			i;

	time = get_time();
	philo->start_time = time;
	philo->last_eat = time;
	i = 0;
	while (i < philo->philo_n)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			kill_process(philo, i);
		if (philo->pid[i] == 0)
		{
			philo->id = i;
			child_do(philo);
		}
		i++;
	}
	parent_do(philo);
}

void	child_do(t_philo *philo)
{
	int	exit_status;

	philo->id++;
	make_loop(philo);
	exit_status = philo->status;
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->die);
	free(philo->pid);
	free(philo);
	exit(exit_status);
}

void	parent_do(t_philo *philo)
{
	pid_t	child_pid;
	int		status;
	int		i;

	i = 0;
	while (i < philo->philo_n)
	{
		child_pid = waitpid(-1, &status, 0);
		if (status != 0)
		{
			clean_process(philo, child_pid);
			return ;
		}
		i++;
	}
}

void	kill_process(t_philo *philo, int index)
{
	int	i;

	i = 0;
	while (i < index)
		kill(philo->pid[i++], SIGKILL);
	error(5);
}

void	clean_process(t_philo *philo, pid_t child_pid)
{
	int	i;

	i = -1;
	while (++i < philo->philo_n)
	{
		if (philo->pid[i] == child_pid)
			break ;
	}
	sem_wait(philo->die);
	philo_printf(philo, i + 1, "died");
	sem_post(philo->die);
	i = 0;
	while (i < philo->philo_n)
		kill(philo->pid[i++], SIGKILL);
}
