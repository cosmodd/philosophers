/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:56:13 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/16 10:22:55 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints the usage of the program.
 */
void	print_usage(void)
{
	printf("\n  \e[37;45;1;3m USAGE \e[0m\n\n");
	printf(" \e[90;3m./philo \e[0m");
	printf("\e[32;1;3m<philo_count> \e[0m");
	printf("\e[33;1;3m<die_time> \e[0m");
	printf("\e[34;1;3m<eat_time> \e[0m");
	printf("\e[36;1;3m<sleep_time> \e[0m");
	printf("\e[90;3m[eat_count] \e[0m");
	printf("\n\n");
	printf(" \e[90;3mEach arguments should only contains digits.\e[0m\n");
	printf(" \e[90;3m<arg> -> required argument.\e[0m\n");
	printf(" \e[90;3m[arg] -> optional argument.\e[0m\n");
	printf("\n");
}

/**
 * @brief Prints the given error message with a specific format.
 *
 * @param error Message to print
 */
void	print_error(char *error)
{
	printf("\e[37;41;1;3m ERROR \e[0m\e[37;3m %s \e[0m\n", error);
}

void	print_warn(char *warn)
{
	printf("\e[37;43;1;3m WARNING \e[0m\e[37;3m %s \e[0m\n", warn);
}
