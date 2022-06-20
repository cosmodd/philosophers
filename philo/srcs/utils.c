/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:52:54 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/20 10:23:29 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	simple_atoi(const char *str)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	while (str[i] && is_digit(str[i]))
		number = number * 10 + str[i++] - '0';
	return (number);
}

long	simple_atol(const char *str)
{
	long	number;
	int		i;

	number = 0;
	i = 0;
	while (str[i] && is_digit(str[i]))
		number = number * 10 + str[i++] - '0';
	return (number);
}
