/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:23:25 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 13:47:22 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_ready(t_args *args)
{
	pthread_mutex_lock(&args->start);
	if (!args->ready)
	{
		pthread_mutex_unlock(&args->start);
		return (0);
	}
	pthread_mutex_unlock(&args->start);
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		new_time;

	gettimeofday(&time, NULL);
	new_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (new_time);
}

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

int	ft_strcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (str1 - str2);
}

void	ft_usleep(long long sleep_time)
{
	long long	start;

	start = get_time();
	while (start + sleep_time > get_time())
		usleep(100);
}
