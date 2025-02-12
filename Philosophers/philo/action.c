/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:30:13 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/22 13:06:54 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	get_ready(t_philo *philo);
static int	get_fork(t_philo *philo);
static int	philo_eat(t_philo *philo);
static int	is_turn(t_philo *philo);

void	*thread_work(void *data)
{
	t_philo	*philo;

	philo = data;
	get_ready(philo);
	if (philo->args->eat_count == 0)
		return (0);
	while (is_alive(philo->args))
	{
		if (!get_fork(philo) || !philo_eat(philo) || !is_alive(philo->args))
			break ;
		philo_printf(philo, philo->id, "is sleeping");
		ft_usleep(philo->args->time_to_sleep);
		if (!is_alive(philo->args))
			break ;
		philo_printf(philo, philo->id, "is thinking");
		if (is_turn(philo))
		{
			if (philo->args->diff <= 0)
				usleep(philo->args->time_to_eat * 1000);
			else if (philo->args->diff <= philo->args->time_to_eat)
				usleep((philo->args->time_to_eat - philo->args->diff) * 1000);
		}
	}
	return (0);
}

int	get_fork(t_philo *philo)
{
	if (philo->args->philo_n == 1)
	{
		pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
		philo_printf(philo, philo->id, "has taken a fork");
		pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
		return (0);
	}
	if (philo->id + 1 < philo->args->philo_n)
	{
		pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
		philo_printf(philo, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
		philo_printf(philo, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
		philo_printf(philo, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
		philo_printf(philo, philo->id, "has taken a fork");
	}
	return (1);
}

int	philo_eat(t_philo *philo)
{
	int	res;

	if (!is_alive(philo->args))
	{
		pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
		return (0);
	}
	philo_printf(philo, philo->id, "is eating");
	pthread_mutex_lock(&philo->args->last_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->args->last_eat);
	ft_usleep(philo->args->time_to_eat);
	pthread_mutex_lock(&philo->args->eat_cnt);
	philo->eat_count++;
	if (philo->args->eat_count < 0)
		res = 1;
	else
		res = (philo->eat_count < philo->args->eat_count);
	pthread_mutex_unlock(&philo->args->eat_cnt);
	pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
	return (res);
}

void	get_ready(t_philo *philo)
{
	long long	time;

	time = get_time();
	philo->last_eat = time;
	philo->start_time = time;
	while (!is_ready(philo->args))
	{
	}
	pthread_mutex_lock(&philo->args->last_eat);
	time = get_time();
	philo->last_eat = time;
	philo->start_time = time;
	pthread_mutex_unlock(&philo->args->last_eat);
	if (philo->args->philo_n > 1 && philo->id % 2 == 0)
	{
		if (is_turn(philo))
			usleep(philo->args->time_to_eat * 2000);
		else
			usleep(philo->args->time_to_eat * 1000);
	}
}

int	is_turn(t_philo *philo)
{
	if (philo->args->philo_n % 2 == 0)
		return (0);
	pthread_mutex_lock(&philo->args->turn);
	if (philo->args->is_turn == philo->id)
	{
		philo->args->is_turn = (philo->args->is_turn + 1) \
								% philo->args->philo_n;
		pthread_mutex_unlock(&philo->args->turn);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->turn);
	return (0);
}
