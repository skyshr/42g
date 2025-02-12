/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:02:17 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 12:32:39 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	error(int exit_status)
{
	if (exit_status == 1)
	{
		printf("wrong usage: ./philo_bonus [philo_n] [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep] (eat_count)\n");
	}
	else if (exit_status == 2)
		printf("malloc error\n");
	else if (exit_status == 3)
		printf("invalid input: input positive int values\n");
	else if (exit_status == 4)
		printf("semaphore open error\n");
	else if (exit_status == 5)
		printf("fork error\n");
	exit(exit_status);
}
