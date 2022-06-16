/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:03:48 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/16 08:55:29 by mrattez          ###   ########.fr       */
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
