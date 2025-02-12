/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:38:46 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 15:35:59 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_for_fork(t_philo *philo)
{
	int	cycle;

	cycle = philo->philo_n / 2;
	if ((philo->id == philo->philo_n && philo->eat_cnt % cycle == 0) || \
		(philo->id < philo->philo_n && philo->eat_cnt % cycle == \
		(philo->id / 2 + philo->id % 2) % cycle))
	{
		if (philo->time_to_sleep <= philo->time_to_eat || \
			philo->time_to_sleep <= 2 * philo->time_to_eat)
			ft_usleep(philo, 2 * philo->time_to_eat - philo->time_to_sleep \
					, philo->time_to_die - (get_time() - philo->last_eat));
	}
}
