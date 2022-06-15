/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:27:05 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/15 14:49:39 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *actor, char *action)
{
	printf("\e[37;44;1;3m %8ld ms \e[45;37m %3d \e[0;37;1m %s\e[0m\n",
		get_time_ms() - actor->room->times.start,
		actor->id, action);
}
