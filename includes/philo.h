/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:44:33 by rabiner           #+#    #+#             */
/*   Updated: 2025/10/04 15:22:21 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

/*
	Fonctions autorisees:

	write, printf, malloc, free, memset
	usleep, gettimeofday
	
	pthread:
			_create			_detach				_join
			_mutex_init		_mutex_destroy
			_mutex_lock		_mutex_unlock
*/

# define MAX_PHILOS 200

# define ERR_ARGC "Error: wrong number of arguments\n"
# define ERR_NOT_DIGIT "Error: argument %d is not a digit\n"
# define ERR_INVALID_INT "Error: argument value must be positive.\n"
# define ERR_PHILO_MAX "Error: num of philosophers must be between 1 & %d\n"

typedef struct s_table	t_table;
typedef struct s_data
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	time_t				last_meal;
	pthread_mutex_t		meal_time_lock;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_table				*table;
}						t_data;

typedef struct s_table
{
	time_t				start_time;
	unsigned int		nb_philos;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					must_eat_count;
	int					sim_stop;
	pthread_mutex_t		sim_stop_lock;
	pthread_mutex_t		write_lock;
	unsigned int		finished_philos;
	pthread_mutex_t		finished_lock;
	pthread_mutex_t		fork_locks[MAX_PHILOS];
	t_data				philos[MAX_PHILOS];
}						t_table;

// init.c
int		init_table(t_table *table, int ac, char **av);
int		init_philosophers(t_table *table);
int		init_mutexes(t_table *table);
void	assign_forks(t_table *table);

// parsing.c
int		is_valid_input(int ac, char **av);

//parsing_utils.c
int		is_only_digits(char *str);
int		ft_atoi(char *str);
int		validate_digits(char *arg, int index);

// utils.c
void	destroy_mutexes(t_table *table);
void	destroy_base_mutexes(t_table *table, unsigned int fork_count);
void	safe_print(t_table *table, int id, char *str);

// philo.c
void	*philo_routine(void *arg);

// philo_actions.c
void	eat(t_data *philo);
void	sleep_and_think(t_data *philo);
void	take_forks(t_data *philo);
void	drop_forks(t_data *philo);

// monitor.c
void	monitor(t_table *tabel);
int		get_sim_stop(t_table *table);
void	set_sim_stop(t_table *table);
int		check_all_ate(t_table *table);

// threads.c
void	join_created_threads(t_table *table, unsigned int threads_created);
int		create_threads(t_table *table);
void	join_threads(t_table *table);

// time.c
long	get_time(void);
void	ft_usleep(unsigned int t_ms, t_table *table);
void	prepare_start_time(t_table *table);

#endif
