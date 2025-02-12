/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 20:17:18 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/22 13:02:26 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	destroy_thread(t_philo *philo, t_args *args, int exit_status);

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_args		*args;
	int			i;

	if (argc != 5 && argc != 6)
		return (error(1));
	args = init_args(argc, argv);
	if (!args)
		return (error(2));
	philo = init_philo(args);
	if (!philo)
		return (destroy_thread(philo, args, 1));
	i = -1;
	while (++i < args->philo_n)
	{
		if (pthread_create(&philo[i].thread, NULL, \
			thread_work, &philo[i]) != 0)
			return (destroy_thread(philo, args, 2));
	}
	usleep(150000);
	monitoring(philo, args);
	i = 0;
	while (i < args->philo_n)
		pthread_join(philo[i++].thread, NULL);
	return (destroy_thread(philo, args, 0));
}

int	destroy_thread(t_philo *philo, t_args *args, int exit_status)
{
	int	i;

	if (exit_status == 1)
		printf("init error\n");
	else if (exit_status == 2)
		printf("pthread_create error\n");
	i = 0;
	while (i < args->philo_n)
	{
		pthread_mutex_destroy(&(args->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&args->print);
	pthread_mutex_destroy(&args->monitor);
	pthread_mutex_destroy(&args->eat_cnt);
	pthread_mutex_destroy(&args->last_eat);
	pthread_mutex_destroy(&args->start);
	pthread_mutex_destroy(&args->turn);
	free(args->fork);
	free(args);
	free(philo);
	return (exit_status);
}
