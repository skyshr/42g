/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 07:49:38 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/18 12:40:44 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <string.h>	// memset
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// write, usleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread~,
# include <semaphore.h>	// sem~
# include <fcntl.h>		// O_CREATE
# include <sys/wait.h>	// waitpid
# include <signal.h>	// kill

# define SEM1 "sem_fork"
# define SEM2 "sem_print"
# define SEM3 "sem_die"

# define EAT_ALL	0
# define DEAD		1
# define ALIVE		2
# define TAKE_FORK	3
# define EAT		4
# define SLEEP		5
# define THINK		6

typedef struct s_philo
{
	int				philo_n;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				eat_count;
	int				id;
	int				eat_cnt;
	int				status;
	long long		last_eat;
	long long		start_time;
	pid_t			*pid;
	pthread_t		thread;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*die;
}	t_philo;

/* init.c */
t_philo		*init_philo(int argc, char **argv);

/* create_process.c */
void		make_process(t_philo *philo);

/* action.c */
void		make_loop(t_philo *philo);

/* think_utils.c */
void		wait_for_fork(t_philo *philo);

/* error.c */
void		error(int exit_status);

/* utils.c */
int			ft_atoi(char *str);
long long	get_time(void);
void		philo_printf(t_philo *philo, int id, char *msg);
int			is_dead(t_philo *philo);
void		ft_usleep(t_philo *philo, long long sleep_time, long long die_time);

#endif