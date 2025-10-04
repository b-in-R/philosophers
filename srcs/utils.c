/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:53:45 by binr              #+#    #+#             */
/*   Updated: 2025/10/04 12:43:18 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutexes(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->fork_locks[i]);
		i++;
	}
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->philos[i].meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&table->finished_lock);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->sim_stop_lock);
}

void	destroy_base_mutexes(t_table *table, unsigned int fork_count)
{
	while (fork_count > 0)
	{
		fork_count--;
		pthread_mutex_destroy(&table->fork_locks[fork_count]);
	}
	pthread_mutex_destroy(&table->finished_lock);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->sim_stop_lock);
}

void	safe_print(t_table *table, int id, char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&table->write_lock);
	if (!get_sim_stop(table)
		|| (msg[0] == 'd'
			&& msg[1] == 'i'
			&& msg[2] == 'e'
			&& msg[3] == 'd'
			&& msg[4] == '\0'))
	{
		timestamp = get_time() - table->start_time;
		printf("%lld %d %s\n", timestamp, id + 1, msg);
	}
	pthread_mutex_unlock(&table->write_lock);
}
