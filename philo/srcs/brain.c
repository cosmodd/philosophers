/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:40:57 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/15 15:17:12 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *self)
{
	time_t	now;
	bool	dead;

	now = get_time_ms();
	dead = ((now - self->last_eat) >= self->room->times.die);
	pthread_mutex_lock(&self->room->death);
	if (!self->room->philo_dead && dead)
	{
		self->room->philo_dead = true;
		print_action(self, "died 💀");
	}
	pthread_mutex_unlock(&self->room->death);
	return (dead || self->room->philo_dead);
}

static bool	do_eat(t_philo *self)
{
	if (is_dead(self) || self->room->philo_dead)
		return (false);
	if (!take_forks(self))
		return (false);
	self->last_eat = get_time_ms();
	print_action(self, "is eating 🍜");
	philo_wait(self, self->room->times.eat);
	return_forks(self);
	return (true);
}

static bool	do_sleep(t_philo *self)
{
	if (is_dead(self) || self->room->philo_dead)
		return (false);
	print_action(self, "is sleeping 😴");
	philo_wait(self, self->room->times.sleep);
	return (true);
}

static bool	do_think(t_philo *self)
{
	if (is_dead(self) || self->room->philo_dead)
		return (false);
	print_action(self, "is thinking 💭");
	return (true);
}

void	*brain(void *arg)
{
	t_philo	*self;

	self = (t_philo *)arg;
	while (self->room->philo_dead == false)
		if (!(do_eat(self) && do_sleep(self) && do_think(self)))
			return (NULL);
	return (NULL);
}
