/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:40:11 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/15 15:14:55 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct s_fork
{
	int				id;
	bool			available;
	pthread_mutex_t	mutex;
	struct s_fork	*next;
	struct s_fork	*prev;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	time_t			last_eat;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread;
	struct s_room	*room;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_times
{
	time_t	start;
	time_t	die;
	time_t	eat;
	time_t	sleep;
}	t_times;

typedef struct s_room
{
	int				philo_count;
	int				eat_count;
	bool			philo_dead;
	t_times			times;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	death;
}	t_room;

void	print_action(t_philo *actor, char *action);
bool	is_dead(t_philo *self);
void	*brain(void *arg);
bool	is_digit(char *string);
void	print_usage(void);
void	print_error(char *error);
bool	take_forks(t_philo *self);
void	return_forks(t_philo *self);
void	init_forks(t_room *room);
void	init_philos(t_room *room);
void	init_room(t_room *room, int ac, char **av);
time_t	get_time_ms(void);
void	wait_time(time_t time);
bool	philo_wait(t_philo *self, time_t time);

#endif
