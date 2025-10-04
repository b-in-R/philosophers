/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:55:32 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 14:57:22 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_created_threads(t_table *table, unsigned int threads_created)
{
	while (threads_created > 0)
	{
		--threads_created;
		pthread_join(table->philos[threads_created].thread, NULL);
	}
}

int	create_threads(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, philo_routine,
				&table->philos[i]) != 0)
		{
			printf("Error: thread for philo %d fail\n", i + 1);
			set_sim_stop(table);
			join_created_threads(table, i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	join_threads(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
