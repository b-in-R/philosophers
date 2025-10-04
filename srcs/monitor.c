/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:28:19 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 12:36:35 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_all_ate(t_table *table)
{
	int	all_finished;

	all_finished = 0;
	pthread_mutex_lock(&table->finished_lock);
	if (table->finished_philos == table->nb_philos)
		all_finished = 1;
	pthread_mutex_unlock(&table->finished_lock);
	return (all_finished);
}

int	check_philo_death(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_time_lock);
		if (get_time() - table->philos[i].last_meal > table->time_to_die)
		{
			safe_print(table, table->philos[i].id, "died");
			set_sim_stop(table);
			pthread_mutex_unlock(&table->philos[i].meal_time_lock);
			return (1);
		}
		pthread_mutex_unlock(&table->philos[i].meal_time_lock);
		i++;
	}
	return (0);
}

void	monitor(t_table *table)
{
	while (!get_sim_stop(table))
	{
		if (check_philo_death(table))
		{
			set_sim_stop(table);
			return ;
		}
		if (table->must_eat_count != -1 && check_all_ate(table))
		{
			set_sim_stop(table);
			return ;
		}
		usleep(1000);
	}
	return ;
}

int	get_sim_stop(t_table *table)
{
	int	value;

	value = 0;
	pthread_mutex_lock(&table->sim_stop_lock);
	value = table->sim_stop;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (value);
}

void	set_sim_stop(t_table *table)
{
	pthread_mutex_lock(&table->sim_stop_lock);
	table->sim_stop = 1;
	pthread_mutex_unlock(&table->sim_stop_lock);
}
