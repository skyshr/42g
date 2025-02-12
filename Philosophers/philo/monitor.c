/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:45:04 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/22 13:05:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int			check_eat_cnt(t_philo *philo, t_args *args);
static long long	last_eat(t_philo *philo);

void	monitoring(t_philo *philo, t_args *args)
{
	int	i;

	pthread_mutex_lock(&args->start);
	args->ready = 1;
	pthread_mutex_unlock(&args->start);
	usleep(60000);
	while (is_alive(args))
	{
		if (check_eat_cnt(philo, args) == args->eat_count)
		{
			change_monitor(args);
			break ;
		}
		i = 0;
		while (i < args->philo_n)
		{
			if (last_eat(&philo[i]) > args->time_to_die)
			{
				philo_printf(&philo[i], philo[i].id, "died");
				break ;
			}
			i++;
		}
		usleep(10);
	}
}

int	is_alive(t_args *args)
{
	pthread_mutex_lock(&args->monitor);
	if (!args->alive)
	{
		pthread_mutex_unlock(&args->monitor);
		return (0);
	}
	pthread_mutex_unlock(&args->monitor);
	return (1);
}

void	change_monitor(t_args *args)
{
	pthread_mutex_lock(&args->monitor);
	args->alive = 0;
	pthread_mutex_unlock(&args->monitor);
}

int	check_eat_cnt(t_philo *philo, t_args *args)
{
	int	i;
	int	res;

	i = 0;
	res = args->eat_count;
	if (res <= 0)
		return (0);
	while (i < args->philo_n)
	{
		pthread_mutex_lock(&philo->args->eat_cnt);
		if (philo[i].eat_count < res)
		{
			res = philo[i].eat_count;
			pthread_mutex_unlock(&philo->args->eat_cnt);
			return (res);
		}
		pthread_mutex_unlock(&philo->args->eat_cnt);
		i++;
	}
	return (res);
}

long long	last_eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->args->last_eat);
	time = philo->last_eat;
	pthread_mutex_unlock(&philo->args->last_eat);
	return (get_time() - time);
}
