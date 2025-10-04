/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:39:17 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 14:56:05 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	validate_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf(ERR_ARGC);
		return (0);
	}
	return (is_valid_input(ac, av));
}

int	start_simulation(t_table *table)
{
	prepare_start_time(table);
	if (!create_threads(table))
		return (0);
	monitor(table);
	join_threads(table);
	return (1);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!validate_args(ac, av))
		return (EXIT_FAILURE);
	if (!init_table(&table, ac, av))
		return (EXIT_FAILURE);
	if (!init_mutexes(&table))
		return (EXIT_FAILURE);
	if (!init_philosophers(&table))
	{
		destroy_base_mutexes(&table, table.nb_philos);
		return (EXIT_FAILURE);
	}
	if (!start_simulation(&table))
	{
		destroy_mutexes(&table);
		return (EXIT_FAILURE);
	}
	destroy_mutexes(&table);
	return (EXIT_SUCCESS);
}
