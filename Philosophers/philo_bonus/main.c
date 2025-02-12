/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:59:18 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 12:03:14 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	free_all(t_philo *philo);

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		error(1);
	philo = init_philo(argc, argv);
	if (philo->eat_count)
		make_process(philo);
	free_all(philo);
	return (0);
}

void	free_all(t_philo *philo)
{
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->die);
	sem_unlink(SEM1);
	sem_unlink(SEM2);
	sem_unlink(SEM3);
	free(philo->pid);
	free(philo);
}
