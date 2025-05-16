/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:53:45 by binr              #+#    #+#             */
/*   Updated: 2025/05/16 15:06:34 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	error_exit(const char *error)
{
	printf("Error:\t%s\n", error);
	exit(EXIT_FAILURE);
}

void	start_error_exit()
{
	printf("4 or 5 args needed\nav[1]: nbr of philos\n \
		\rav[2]: time_to_die (ms)\nav[3]: time_to_eat(ms)\n \
		\rav[4]: time_to_sleep(ms)\n \
		\rav[5]: nbr_of_time_each_philo_must_eat (optional)\n");
	exit(EXIT_FAILURE);
}