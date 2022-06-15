/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:32:58 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/15 15:14:47 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	wait_time(time_t time)
{
	time_t			start;
	time_t			end;

	start = get_time_ms();
	end = start + time;
	while (start < end)
	{
		start = get_time_ms();
		usleep(10);
	}
}

bool	philo_wait(t_philo *self, time_t time)
{
	time_t	start;
	time_t	end;

	start = get_time_ms();
	end = start + time;
	while (start < end)
	{
		start = get_time_ms();
		if (is_dead(self))
			return (false);
		usleep(10);
	}
	return (true);
}
