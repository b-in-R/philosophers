/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:05:50 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 15:06:02 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_data *philo)
{
	unsigned int	times_ate;

	safe_print(philo->table, philo->id, "is eating");
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time();
	philo->times_ate++;
	times_ate = philo->times_ate;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (philo->table->must_eat_count != -1
		&& times_ate == (unsigned int)philo->table->must_eat_count)
	{
		pthread_mutex_lock(&philo->table->finished_lock);
		philo->table->finished_philos++;
		pthread_mutex_unlock(&philo->table->finished_lock);
	}
	ft_usleep(philo->table->time_to_eat, philo->table);
}

void	sleep_and_think(t_data *philo)
{
	safe_print(philo->table, philo->id, "is sleeping");
	ft_usleep(philo->table->time_to_sleep, philo->table);
	safe_print(philo->table, philo->id, "is thinking");
}

void	take_forks(t_data *philo)
{
	pthread_mutex_lock(philo->left_fork);
	safe_print(philo->table, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	safe_print(philo->table, philo->id, "has taken a fork");
}

void	drop_forks(t_data *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
