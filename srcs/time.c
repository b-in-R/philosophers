/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:05:57 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/12 15:32:37 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

// oceano 1:20:00 - 1:21:50
void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;
	
	start = gettime(MICROS);
	while (gettime(MICROS) - start < usec)
	{
		if (simalutaion_finished(data))
			break;
		elapsed = gettime(MICROS) - start;
		rem = usec - elapsed;
		
		if (rem > 1e3)
			usleep(usec / 2);
		else
		{
			while (gettime(MICROS) - start < usec)
				;
		}
	}
}

// oceano 1:10:00  - 1:14:00
long	gettime(t_time_code time_code)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		error_exit("gettimeofday failed\n");
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLIS == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROS == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("wrong arg in gettime\n");
	return (NULL);
}