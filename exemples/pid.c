
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int ac, char **av)
{
	int	pid1;
	int	pid2;
	int	pid1_res;
	int	pid2_res;

	pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error fork1\n");
		return 1;
	}
	if (pid1 == 0)
	{
		sleep(2);
		printf("pid1 ok\t\tid: %d\n", getpid());
		return 0;
	}

	pid2 = fork();
	if (pid2 == -1)
	{
		printf("Error fork2\n");
		return 1;
	}
	if (pid2 == 0)
	{
		sleep(1);
		printf("pid2 ok\t\tid: %d\n", getpid());
		return 0;
	}
	pid1_res = waitpid(pid2, NULL, 0);
	pid2_res = waitpid(pid1, NULL, 0);

//	pid1_res = waitpid(pid1, NULL, WNOHANG); avec WNOHANG: retrourne immediatement meme si le pid concerne n'est pas termine, et va enregister le resultat dans le 2eme param

	printf("waited for pid %d\n", pid1_res);
	printf("waited for pid %d\n", pid2_res);

	return 0;
}