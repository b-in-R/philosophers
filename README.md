4.05

----------------------------------------------------------------------------------------------------
Fonctions:

		usleep:					int	usleep(useconds_t usec);		#include <unistd.h>

							appel:	if (usleep(1000000))
										error_exit;
					
							suspend l'execution du thread appele (micro sec)
							min 0	max 1000000

							return:	0 success, 1 failure
							

		gettimeofday:		int	gettimeofday(struct timeval *tv, struct timezone *tz);
																		(NULL)
							appel: 	{...
									struct timeval	tv;

									gettimeofday(&tv, NULL);
									...}


							struct timeval
							{
								time_t		tv_sec;		/* seconds */
								suseconds_t	tv_usec;	/* microseconds */
							};

							obsolete:
							struct timezone
							{
								int	tz_minuteswest;		/* minutes west of Greenwich */
								int	tz_dsttime;			/* type of DST correction */
							};

							return: 0 success, -1 failure

	pthread:
		
		_create:			int	prhread_create(pthread_t *thread, const pthread_attr_t *attr,
												void *(*start_routine) (void *), void *arg);

							start un nouveau thread dans le processus

							return: 0 success, any_n failure

		_join:

		_detach:

		_mutex_init:

		_mutex_destroy:

		_mutex_lock:

		_mutex_unlock:


----------------------------------------------------------------------------------------------------