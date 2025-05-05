/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:54:55 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/04 15:40:47 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	struct timeval	tv;
	char			buffer[30];
	time_t			curtime;

	gettimeofday(&tv, NULL);
	curtime = tv.tv_sec;
	strftime(buffer, 30, "%d-%m-%Y   %T.", localtime(&curtime));
	printf("%s\n%ld\n", buffer, tv.tv_sec);
	return (0);
}