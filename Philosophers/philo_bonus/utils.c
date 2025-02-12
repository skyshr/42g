/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:55:21 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 13:47:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		new_time;

	gettimeofday(&time, NULL);
	new_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (new_time);
}

void	philo_printf(t_philo *philo, int id, char *msg)
{
	long long	time;

	sem_wait(philo->print);
	time = get_time() - philo->start_time;
	printf("%lld %d %s\n", time, id, msg);
	sem_post(philo->print);
}

int	is_dead(t_philo *philo)
{
	long long	time;

	time = get_time();
	if (time - philo->last_eat > philo->time_to_die)
	{
		philo->status = DEAD;
		return (1);
	}
	return (0);
}

void	ft_usleep(t_philo *philo, long long sleep_time, long long die_time)
{
	long long	start_time;
	long long	time;

	start_time = get_time();
	while (1)
	{
		time = get_time() - start_time;
		if (sleep_time <= time)
			break ;
		if (die_time < time)
		{
			philo->status = DEAD;
			break ;
		}
		usleep(100);
	}
}
