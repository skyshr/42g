/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:59:55 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/15 18:44:27 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(int exit_status)
{
	if (exit_status == 1)
	{
		printf("usage: ./philo [philo_n] [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep] (eat_count)\n");
	}
	else if (exit_status == 2)
		printf("init error\n");
	return (exit_status);
}
