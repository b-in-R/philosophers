/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:05:57 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 15:02:53 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}

void	ft_usleep(unsigned int time_in_ms, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time();
	while (1)
	{
		if (get_sim_stop(table))
			break ;
		elapsed = get_time() - start;
		if (elapsed >= (long)time_in_ms)
			break ;
		remaining = (long)time_in_ms - elapsed;
		if (remaining > 5)
			usleep((remaining - 5) * 1000);
		else
			usleep(500);
	}
}

void	prepare_start_time(t_table *table)
{
	unsigned int	i;
	long			start_time;

	start_time = get_time();
	table->start_time = start_time;
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_time_lock);
		table->philos[i].last_meal = start_time;
		pthread_mutex_unlock(&table->philos[i].meal_time_lock);
		i++;
	}
}
