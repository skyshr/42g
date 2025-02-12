/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:24:36 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 15:03:02 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	philo_get_fork(t_philo *philo);
static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

void	make_loop(t_philo *philo)
{	
	if (philo->id % 2 == 0)
		ft_usleep(philo, philo->time_to_eat, philo->time_to_die);
	else if (philo->philo_n > 1 && philo->philo_n % 2 == 1 \
			&& philo->id == philo->philo_n)
		ft_usleep(philo, 2 * philo->time_to_eat, philo->time_to_die);
	if (philo->status == DEAD)
		return ;
	philo->status = TAKE_FORK;
	while (philo->status != EAT_ALL && philo->status != DEAD)
	{
		if (philo->status == TAKE_FORK)
			philo_get_fork(philo);
		else if (philo->status == EAT)
			philo_eat(philo);
		else if (philo->status == SLEEP)
			philo_sleep(philo);
		else if (philo->status == THINK)
			philo_think(philo);
	}
}

void	philo_get_fork(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	sem_wait(philo->fork);
	philo_printf(philo, philo->id, "has taken a fork");
	if (philo->philo_n == 1)
	{
		while (!is_dead(philo))
			usleep(100);
		sem_post(philo->fork);
		return ;
	}
	sem_wait(philo->fork);
	philo_printf(philo, philo->id, "has taken a fork");
	philo->status = EAT;
}

void	philo_eat(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	philo->last_eat = get_time();
	philo_printf(philo, philo->id, "is eating");
	while (get_time() < philo->last_eat + philo->time_to_eat)
	{
		if (is_dead(philo))
			return ;
		usleep(100);
	}
	sem_post(philo->fork);
	sem_post(philo->fork);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->eat_count)
		philo->status = EAT_ALL;
	else
		philo->status = SLEEP;
}

void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	philo_printf(philo, philo->id, "is sleeping");
	while (get_time() < philo->last_eat + philo->time_to_eat + \
						philo->time_to_sleep)
	{
		if (is_dead(philo))
			return ;
		usleep(100);
	}
	philo->status = THINK;
}

void	philo_think(t_philo *philo)
{
	philo_printf(philo, philo->id, "is thinking");
	if (philo->philo_n % 2 == 1)
		wait_for_fork(philo);
	else if (philo->time_to_sleep <= philo->time_to_eat)
	{
		ft_usleep(philo, philo->time_to_eat - philo->time_to_sleep \
				, philo->time_to_die - (get_time() - philo->last_eat));
	}
	if (philo->status == DEAD)
		return ;
	usleep(500);
	philo->status = TAKE_FORK;
}
