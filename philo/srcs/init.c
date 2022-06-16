/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:38:42 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/16 08:48:47 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	new_fork(t_fork **fork, t_fork *prev, int id)
{
	(*fork) = malloc(sizeof(t_fork));
	if (*fork == NULL)
		return ;
	(*fork)->id = id;
	(*fork)->available = true;
	pthread_mutex_init(&(*fork)->mutex, NULL);
	if (prev != NULL)
	{
		(*fork)->prev = prev;
		prev->next = (*fork);
	}
	(*fork)->next = NULL;
}

void	init_forks(t_room *room)
{
	t_fork	*node;
	t_fork	*previous;
	int		i;

	i = -1;
	previous = NULL;
	while (++i < room->philo_count)
	{
		new_fork(&node, previous, i);
		if (node == NULL)
		{
			free_forks(room->forks, i);
			return print_error("Couldn't allocate enough fork !");
		}
		if (room->forks == NULL)
			room->forks = node;
		previous = node;
	}
	room->forks->prev = previous;
}

static void	new_philo(t_philo **philo, t_philo *prev, t_fork *fork, int id)
{
	(*philo) = malloc(sizeof(t_philo));
	if (*philo == NULL)
		return ;
	(*philo)->id = id;
	(*philo)->eat_count = 0;
	(*philo)->left_fork = fork->prev;
	(*philo)->right_fork = fork;
	if (prev != NULL)
	{
		(*philo)->prev = prev;
		prev->next = *philo;
	}
	(*philo)->next = NULL;
}

void	init_philos(t_room *room)
{
	t_philo	*node;
	t_philo	*previous;
	t_fork	*fork;
	int		i;

	i = -1;
	previous = NULL;
	fork = room->forks;
	while (++i < room->philo_count)
	{
		new_philo(&node, previous, fork, i);
		if (node == NULL)
		{
			free_philos(room->philos, i);
			return print_error("Couldn't allocate enough philo !");
		}
		node->room = room;
		node->last_eat = room->times.start;
		if (room->philos == NULL)
			room->philos = node;
		previous = node;
		fork = fork->next;
	}
	room->philos->prev = previous;
	previous->next = room->philos;
}

void	init_room(t_room *room, int ac, char **av)
{
	(*room) = (t_room){0};
	room->philo_count = atoi(av[1]);
	room->times.die = atoi(av[2]);
	room->times.eat = atoi(av[3]);
	room->times.sleep = atoi(av[4]);
	if (ac == 6)
		room->eat_count = atoi(av[5]);
	room->times.start = get_time_ms();
	room->philo_dead = 0;
	pthread_mutex_init(&room->death, NULL);
	init_forks(room);
	init_philos(room);
}
