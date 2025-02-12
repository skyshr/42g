/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:00:41 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 12:31:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	init_args(t_philo *philo, int argc, char **argv);

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		error(2);
	init_args(philo, argc, argv);
	philo->id = 0;
	philo->eat_cnt = 0;
	philo->status = ALIVE;
	philo->pid = (pid_t *)malloc(philo->philo_n * sizeof(pid_t));
	if (!philo->pid)
		error(2);
	memset(philo->pid, 0, philo->philo_n * sizeof(pid_t));
	sem_unlink(SEM1);
	sem_unlink(SEM2);
	sem_unlink(SEM3);
	philo->fork = sem_open(SEM1, O_CREAT, 0644, philo->philo_n);
	philo->print = sem_open(SEM2, O_CREAT, 0644, 1);
	philo->die = sem_open(SEM3, O_CREAT, 0644, 1);
	if (philo->fork == SEM_FAILED || philo->print == SEM_FAILED \
		|| philo->die == SEM_FAILED)
		error(4);
	return (philo);
}

void	init_args(t_philo *philo, int argc, char **argv)
{
	philo->philo_n = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->eat_count = -1;
	if (argc == 6)
		philo->eat_count = ft_atoi(argv[5]);
	if (philo->philo_n <= 0 || philo->time_to_die <= 0 || \
		philo->time_to_eat <= 0 || philo->time_to_sleep <= 0 || \
		(argc == 6 && philo->eat_count < 0))
		error(3);
}
