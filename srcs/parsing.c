/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:02:10 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/16 18:51:47 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"


int	is_digit(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (!(str[i] >=  '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// return: 	0 - ok		1 - error
void	parsing(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_digit(av[i]))// voir si isspace
			error_exit("args must contain only positive numbers");
		//suite

		i++;
	}
	printf("TEST OK\n");//suppr
}

