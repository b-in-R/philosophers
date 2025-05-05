

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



void	*func1(void *arg)
{
	t_info	*info;
	t_info	*modif;

	info = arg;
	modif = malloc(sizeof(t_info));
	modif->id = info->id;
	modif->name = strdup(info->name);
	usleep(1000000);
	printf("func1:\nav[1] len:\t%zu\nav[1] txt:\t%s\n\n", info->id, info->name);
	modif->id = info->id * 2;
	modif->name = "ok";
	return (modif);
}


int	main(int ac, char **av)
{
	pthread_t	thread;
	t_info		info;
	t_info		*res;

	if (ac < 2 || strlen(av[1]) < 3)
	{
		printf("error args\n");
		return (0);
	}

	info.id = strlen(av[1]);
	//info.name = calloc(strlen(av[1]), sizeof(char) + 1);
	info.name = av[1];
	pthread_create(&thread, NULL, func1, &info);
/*					|		|		|		|
					|		|		|		-- argument a passer a la fonction
					|		|		-- pointeur vers fnct a executer dans le thread
					|		-- Attributs du thread (NULL par defaut a utiliser)
					-- adresse ou sera stocke l'idantifiant du thread cree
*/
	printf("test1 main\n\n");
	pthread_join(thread, (void **)&res);
	printf("test modif:\n.id:\t%zu\n.name:\t%s\n\n", res->id, res->name);
	free(res);
	printf("info apres func1:\n.id:\t%zu\n.name:\t%s\n\n", info.id, info.name);

	return (0);
}


