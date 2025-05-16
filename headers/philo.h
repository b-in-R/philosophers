/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:44:33 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/16 15:06:57 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# include <time.h>

/*
	Fonctions autorisees:

	write, printf, malloc, free, memset
	usleep, gettimeofday
	
	pthread:
			_create			_detach				_join
			_mutex_init		_mutex_destroy
			_mutex_lock		_mutex_unlock
*/

typedef pthread_mutex_t t_mtx;
typedef struct s_data	t_data;

typedef enum e_time_code
{
	SECOND,
	MILLIS,
	MICROS,
}	t_time_code;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}			t_fork;

typedef struct s_philo
{
	int			id;
	long		meal_n;
	int			full;// a voir (oceano -> bool)
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	tread_id;// philo_id
	t_data		*data;
}				t_philo;

struct s_data
{
	long	philo_nbr;// av[1]
	long	t_to_die;// av[2]
	long	t_to_eat;// av[3]
	long	t_to_sleep;// av[4]
	long	n_of_meals;// av[5]
	long	start_time;
	int		end_simulation;// 1 si un philo meurt ou si tous sont pleins(?)
	t_fork	*forks;
	t_philo	*philos;
};

//parsing.c
void	parsing(int ac, char **av);

// utils.c
void	error_exit(const char *error);
void	start_error_exit();

// time.c
void	precise_usleep(long usec, t_data *table);
long	gettime(t_time_code time_code);


#endif