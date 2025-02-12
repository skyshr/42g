/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 08:29:42 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/16 08:29:59 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_printf(t_philo *philo, int id, char *msg)
{
	long long	time;

	pthread_mutex_lock(&philo->args->print);
	if (!philo->args->alive)
	{
		pthread_mutex_unlock(&philo->args->print);
		return ;
	}
	time = get_time() - philo->start_time;
	printf("%lld %d %s\n", time, id + 1, msg);
	if (ft_strcmp(msg, "died") == 0)
		change_monitor(philo->args);
	pthread_mutex_unlock(&philo->args->print);
}
