

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
	 int	pthread_create(pthread_t *thread, const pthread_attr_t *attr,
							void *(*start_routine)(void *), void *arg);


	CFLAGS = -lpthread
*/


typedef struct s_info
{
	size_t	id;
	char	*name;
}			t_info;


void	*func2(void *arg)
{
	t_info	*info;

	info = arg;
	printf("--- creation thread func2 ---\n");
	printf("func2 func2 (avant modif):\ninfo.id:\t%zu\ninfo.name:\t%s\n\n", info->id, info->name);
	printf("--- fin thread func2 ---\n");
	return (NULL);
}


void	*func1(void *arg)
{
	t_info	*info;
	t_info	*modif;

	printf("--- creation thread func1 ---\n");
	info = arg;
	modif = malloc(sizeof(t_info));
	modif->id = info->id;
	modif->name = strdup(info->name);
	
	printf("func1:\nav[1] len:\t%zu\nav[1] txt:\t%s\n\n", info->id, info->name);
	usleep(300000);// (ms)
	modif->id = info->id * 2;
	modif->name = "ok";
	printf("--- fin thread func1 ---\n");
	return (modif);
}


int	main(int ac, char **av)
{
	pthread_t	thread;
	pthread_t	thread_2;
	t_info		info;
	t_info		*res;

	if (ac < 2 || strlen(av[1]) < 3)
	{
		printf("error args\n");
		return (0);
	}

	info.id = strlen(av[1]);
	info.name = av[1];

	//func1
	pthread_create(&thread, NULL, func1, &info);
/*					|		|		|		|
					|		|		|		-- argument a passer a la fonction
					|		|		-- pointeur vers fnct a executer dans le thread
					|		-- Attributs du thread (NULL par defaut a utiliser)
					-- adresse ou sera stocke l'idantifiant du thread cree
*/
	printf("test main, si en 1er -> ok\n\n");

	//func2
	pthread_create(&thread_2, NULL, func2, &info);
	printf("test usleep %i\n", usleep(300000));
	pthread_join(thread, (void **)&res);

	printf("test modif:\nres.id(*2):\t%zu\nres.name:\t%s\n\n", res->id, res->name);

	usleep(1000000);
	pthread_detach(thread_2);

	free(res);
	printf("info apres func1:\ninfo.id:\t%zu\ninfo.name:\t%s\n\n", info.id, info.name);

	return (0);
}


