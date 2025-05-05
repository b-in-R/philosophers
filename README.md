4.05

----------------------------------------------------------------------------------------------------
Fonctions:

		usleep:					int	usleep(useconds_t usec);		#include <unistd.h>

							appel:	if (usleep(1000000))
										error_exit;
					
							suspend l'execution du thread appele (micro sec)
							min 0	max 1000000

							return:	success -> 0, failure -> 1
							

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

							return: success -> 0, failure -> -1

	pthread:

					#include <pthread.h>
		

		_create:			int	pthread_create(pthread_t *thread, const pthread_attr_t *attr,
												void *(*start_routine) (void *), void *arg);

							appel:
							{ ...
							pthread_t	thread; // obligatoire
							t_info		info; // si arg a passer a la fonction thread (struct ou autre a declarer)

							pthread_create(&thread, NULL, func1, &info);
							... }

							start un nouveau thread dans le processus
							pthread_join ou pthread_detach obligatoire (comme free)

							- voir pthread_create_join.c

							return: success -> 0, failure -> any_n

		_join:				int	pthread_join(pthread_t tread, void **retval);

							appel:
							{ ...
							pthread_t	thread;
							t_info		*res;

							[pthread_create(...);]// necessaire
							pthread_join(thread, (void **)&res);
							... }

							pour rattacher le thread cree a la suite du prog
							peut recuperer la valeur de retour

							return: success -> 0, failure -> any_n

		_detach:			int	pthread_detach(pthread_t thread);

							appel:
							{ ...
							pthread_t	thread;

							[pthread_create(...);]// necessaire
							pthread_detach(thread);
							... }

							pour liberer les ressources du thread cree avec pthread_create

							return: success -> 0, failure -> any_n 

		_mutex_init:		int	pthread_mutex_init(pthread_mutex_t *restrict mutex,
											const pthread_muexattr_t *restrict attr);
							?? pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; ??

		_mutex_destroy:		int	pthread_mutex_destroy(pthread_mutex_t *mutex);

		_mutex_lock:

		_mutex_unlock:


----------------------------------------------------------------------------------------------------