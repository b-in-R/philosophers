/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:19:21 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 14:38:34 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_table(t_table *table, int ac, char **av)
{
	table->nb_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->must_eat_count = ft_atoi(av[5]);
	else
		table->must_eat_count = -1;
	table->sim_stop = 0;
	table->finished_philos = 0;
	table->start_time = get_time();
	return (1);
}

int	init_mutexes_bis(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->fork_locks[i], NULL) != 0)
		{
			destroy_base_mutexes(table, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->sim_stop_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&table->sim_stop_lock);
		return (0);
	}
	if (pthread_mutex_init(&table->finished_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write_lock);
		pthread_mutex_destroy(&table->sim_stop_lock);
		return (0);
	}
	return (init_mutexes_bis(table));
}

int	init_philosophers(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->philos[i].meal_time_lock, NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&table->philos[i].meal_time_lock);
			}
			printf("Error: mutex init failed (meal time)\n");
			return (0);
		}
		table->philos[i].id = i;
		table->philos[i].table = table;
		table->philos[i].times_ate = 0;
		table->philos[i].last_meal = get_time();
		i++;
	}
	assign_forks(table);
	return (1);
}

/* Assign each philosopher's forks, swapping odd IDs to limit deadlocks */
void	assign_forks(t_table *table)
{
	unsigned int	i;
	pthread_mutex_t	*tmp;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philos[i].left_fork = &table->fork_locks[i];
		table->philos[i].right_fork = &table->fork_locks[(i + 1)
			% table->nb_philos];
		if (table->philos[i].id % 2 == 1)
		{
			tmp = table->philos[i].left_fork;
			table->philos[i].left_fork = table->philos[i].right_fork;
			table->philos[i].right_fork = tmp;
		}
		i++;
	}
}
