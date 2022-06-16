/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:39:23 by mrattez           #+#    #+#             */
/*   Updated: 2022/06/16 08:55:29 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 5)
	{
		print_usage();
		return (EXIT_SUCCESS);
	}
	else if (ac > 6)
	{
		print_error("Too many arguments !");
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i++]))
		{
			print_error("Invalid argument !");
			return (EXIT_FAILURE);
		}
	}
	return (-1);
}

static void	launch_philos(t_room *room)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = room->philos;
	while (i < room->philo_count)
	{
		pthread_create(&philo->thread, NULL, brain, philo);
		philo = philo->next->next;
		i += 2;
	}
	usleep(100);
	i = 1;
	philo = room->philos->next;
	while (i < room->philo_count)
	{
		pthread_create(&philo->thread, NULL, brain, philo);
		philo = philo->next->next;
		i += 2;
	}
}

static void	wait_philos(t_room *room)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = room->philos;
	while (i < room->philo_count)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_room	room;
	int		check;

	check = check_args(ac, av);
	if (check >= 0)
		return (check);
	init_room(&room, ac, av);
	launch_philos(&room);
	wait_philos(&room);
	free_room(&room);
	return (EXIT_SUCCESS);
}
