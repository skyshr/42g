/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:20:34 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/22 13:17:23 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutex(t_args *args);
static int	destroy_fork_mutex(t_args *args, int index, int sign);

t_args	*init_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->philo_n = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->diff = args->time_to_sleep - args->time_to_eat;
	args->eat_count = -1;
	args->alive = 1;
	args->ready = 0;
	args->is_turn = 0;
	if (argc == 6)
		args->eat_count = ft_atoi(argv[5]);
	if (args->philo_n <= 0 || args->time_to_die < 0 || \
		args->time_to_eat < 0 || args->time_to_sleep < 0 || \
		(argc == 6 && args->eat_count < 0))
		return (free(args), NULL);
	if (!init_mutex(args))
		return (free(args), NULL);
	return (args);
}

t_philo	*init_philo(t_args *args)
{
	t_philo	*philo;
	int		i;

	if (!args)
		return (NULL);
	philo = malloc(args->philo_n * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < args->philo_n)
	{
		philo[i].id = i;
		philo[i].eat_count = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % args->philo_n;
		philo[i].last_eat = 0;
		philo[i].start_time = 0;
		philo[i].args = args;
		i++;
	}
	return (philo);
}

int	init_mutex(t_args *args)
{
	int	i;

	args->fork = malloc(args->philo_n * sizeof(pthread_mutex_t));
	if (!args->fork)
		return (0);
	i = 0;
	while (i < args->philo_n)
	{
		if (pthread_mutex_init(&(args->fork[i]), NULL) != 0)
			return (destroy_fork_mutex(args, i, 0));
		i++;
	}
	if (pthread_mutex_init(&(args->print), NULL) != 0)
		return (destroy_fork_mutex(args, args->philo_n, 0));
	if (pthread_mutex_init(&(args->monitor), NULL) != 0)
		return (destroy_fork_mutex(args, args->philo_n, 1));
	if (pthread_mutex_init(&(args->eat_cnt), NULL) != 0)
		return (destroy_fork_mutex(args, args->philo_n, 2));
	if (pthread_mutex_init(&(args->last_eat), NULL) != 0)
		return (destroy_fork_mutex(args, args->philo_n, 3));
	if (pthread_mutex_init(&(args->start), NULL) != 0)
		return (destroy_fork_mutex(args, args->philo_n, 4));
	if (pthread_mutex_init(&(args->turn), NULL) != 0)
		return (destroy_fork_mutex(args, args->philo_n, 5));
	return (1);
}

int	destroy_fork_mutex(t_args *args, int index, int sign)
{
	int	i;

	i = 0;
	while (i < index)
		pthread_mutex_destroy(&args->fork[i++]);
	if (sign >= 1)
		pthread_mutex_destroy(&args->print);
	if (sign >= 2)
		pthread_mutex_destroy(&args->monitor);
	if (sign >= 3)
		pthread_mutex_destroy(&args->eat_cnt);
	if (sign >= 4)
		pthread_mutex_destroy(&args->last_eat);
	if (sign >= 5)
		pthread_mutex_destroy(&args->start);
	return (free(args->fork), 0);
}
