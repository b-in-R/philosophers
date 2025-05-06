/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:54:55 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/06 14:28:10 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	struct timeval	tv_base;
	struct timeval	tv_update;
//	char			buffer[30];
	time_t			curtime_sec;
	time_t			curtime_usec;
	time_t			sec_passed;
	time_t			usec_passed;
	
	int				uslp = 300000;


	
	/*
	
	{
		...
		gettimeofday(&tv, NULL);	

		return (tv.sec * 1000 + tv.usec / 1000);	
	}
		
		Usleep a faire precis
	*/


	
	gettimeofday(&tv_base, NULL);
	curtime_sec = tv_base.tv_sec;// 		temps en sec depuis 1.01.1970
	curtime_usec = tv_base.tv_usec;//	temps en microsec dans la sec en cours
	/*
			interdit?
		
			strftime(buffer, 30, "%d-%m-%Y   %T", localtime(&curtime));
			printf("buffer:\t\t%s\n", buffer);
			printf("tv.tv_sec:\t%ld\n", tv.tv_sec);
	*/
	printf("tv.tv_sec:\t\t%ld\n", curtime_sec);
	printf("tv.tv_usec:\t\t%ld\n", curtime_usec);
	
	printf("\nApres usleep\t\t%i usec\n", uslp);
	usleep(uslp);// pas precis
	
	// temps ecoule depuis dernier appel:
	
	gettimeofday(&tv_update, NULL);
	curtime_sec = tv_update.tv_sec;
	curtime_usec = tv_update.tv_usec;

	sec_passed = curtime_sec - tv_base.tv_sec;
	
	printf("\nsec_passed:\t\t%ld\n\n", sec_passed);
	
	printf("tv_base.tv_usec:\t%ld\n", tv_base.tv_usec);
	printf("tv_update.tv_usec:\t%ld\n", tv_update.tv_usec);
	
	/*
		usec_passed va jusqua 999999? 
		si sec_passed = 1:
			usec_reel = (usec_max - usec_base) + usec_passed
	*/	
	if (!sec_passed)
	{
		usec_passed = curtime_usec - tv_base.tv_usec;
	}
	else
	{
		usec_passed = (999999 - tv_base.tv_sec) + tv_update.tv_usec;
	}
	printf("sec_passed:\t\t%ld\n\nusec_passed:\t\t%ld\n\n", sec_passed, usec_passed);
	
	return (0);
}