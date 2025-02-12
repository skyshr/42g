/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 06:39:58 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/22 12:54:34 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>	// memset
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// write, usleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread~, 

typedef struct s_args
{
	int				philo_n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				diff;
	int				eat_count;
	int				alive;
	int				ready;
	int				is_turn;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	monitor;
	pthread_mutex_t	eat_cnt;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	start;
	pthread_mutex_t	turn;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				left_fork;
	int				right_fork;
	long long		last_eat;
	long long		start_time;
	pthread_t		thread;
	struct s_args	*args;
}	t_philo;

/* init.c */
t_args		*init_args(int argc, char **argv);
t_philo		*init_philo(t_args *args);

/* utils.c */
int			is_ready(t_args *args);
long long	get_time(void);
int			ft_atoi(char *str);
int			ft_strcmp(char *str1, char *str2);
void		ft_usleep(long long sleep_time);

/* action.c */
void		*thread_work(void *data);

/* monitor.c */
void		monitoring(t_philo *philo, t_args *args);
void		change_monitor(t_args *args);
int			is_alive(t_args *args);

/* error.c */
int			error(int exit_status);

/* print.c */
void		philo_printf(t_philo *philo, int id, char *msg);

#endif