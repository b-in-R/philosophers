/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:54:55 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/16 15:08:37 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac == 5 || ac == 6)// ok
	{
		//	1)	check_erreurs et parse input
		parsing(ac, av);

		//	2)	data_init
		
		
		//	3)	start_simulation

		
		//	4)	leaks
		
	}
	else
		start_error_exit();
	return (0);
}