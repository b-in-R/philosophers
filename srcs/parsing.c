/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:02:10 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 15:00:56 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	parse_argument(char *arg, int *number)
{
	*number = ft_atoi(arg);
	if (*number == -1)
		return (printf(ERR_INVALID_INT), 0);
	return (1);
}

static int	validate_philo_count(int index, int number)
{
	if (index != 1)
		return (1);
	if (number < 1 || number > MAX_PHILOS)
		return (printf(ERR_PHILO_MAX, MAX_PHILOS), 0);
	return (1);
}

static int	validate_required_times(int index, int number)
{
	if (index < 2 || index > 4)
		return (1);
	if (number <= 0)
		return (printf(ERR_INVALID_INT), 0);
	return (1);
}

static int	validate_optional_arg(int argc, int index, int number)
{
	if (argc != 6 || index != 5)
		return (1);
	if (number <= 0)
	{
		printf("Error: num_of_times_philosopher_must_eat must be > 0\n");
		return (0);
	}
	return (1);
}

int	is_valid_input(int argc, char **argv)
{
	int	index;
	int	number;

	index = 1;
	while (index < argc)
	{
		if (!validate_digits(argv[index], index))
			return (0);
		if (!parse_argument(argv[index], &number))
			return (0);
		if (!validate_philo_count(index, number))
			return (0);
		if (!validate_required_times(index, number))
			return (0);
		if (!validate_optional_arg(argc, index, number))
			return (0);
		index++;
	}
	return (1);
}
