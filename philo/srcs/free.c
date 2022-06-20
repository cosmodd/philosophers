/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:46:02 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/20 09:07:16 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo *philos, int count)
{
	t_philo	*current;
	t_philo	*next;
	int	i;

	i = 0;
	current = philos;
	while (i < count)
	{
		next = current->next;
		pthread_detach(philos->thread);
		free(current);
		current = next;
		i++;
	}
}

void	free_forks(t_fork *forks, int count)
{
	t_fork	*current;
	t_fork	*next;
	int		i;

	i = 0;
	current = forks;
	while (i < count)
	{
		next = current->next;
		pthread_mutex_destroy(&current->mutex);
		free(current);
		current = next;
		i++;
	}
}

void	free_room(t_room *room)
{
	free_philos(room->philos, room->philo_count);
	free_forks(room->forks, room->philo_count);
	pthread_mutex_destroy(&room->death);
}