/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:03:48 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/16 10:28:07 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if the string contains only digits.
 *
 * @param string String to check
 * @return true if the string contains only digits, false otherwise
 */
bool	is_number(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] < '0' || string[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	validate_room(t_room *room)
{
	if (room->philo_count >= 200)
		print_warn("A lot of philosophers could lead to unwanted behavior.");
	if (room->times.die < 60 || room->times.eat < 60 || room->times.sleep < 60)
		print_warn("Times below 60 are not recommended.");
	if (room->times.die < 0)
	{
		print_error("Die time must be positive.");
		return (false);
	}
	if (room->times.eat < 0)
	{
		print_error("Eat time must be positive.");
		return (false);
	}
	if (room->times.sleep < 0)
	{
		print_error("Sleep time must be positive.");
		return (false);
	}
	if (room->eat_count < 0)
	{
		print_error("Eat count must be positive.");
		return (false);
	}
	return (true);
}
