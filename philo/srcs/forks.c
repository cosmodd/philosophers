/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:41:42 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/15 13:55:26 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->available = false;
}

static void	return_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mutex);
	fork->available = true;
}

bool	take_forks(t_philo *self)
{
	while (!self->right_fork->available)
		if (is_dead(self))
			return (false);
	take_fork(self->right_fork);
	print_action(self, "has taken a fork 🍴");
	while (!self->left_fork->available)
		if (is_dead(self))
			return (false);
	take_fork(self->left_fork);
	print_action(self, "has taken a fork 🍴");
	return (true);
}

void	return_forks(t_philo *self)
{
	return_fork(self->left_fork);
	return_fork(self->right_fork);
}
