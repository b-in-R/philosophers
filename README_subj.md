
Philosophers:

	sujet:

		-	1 philosophe ou plus sont assis a une table ronde, a manger au milieu
		-	chaque philo tour apres tour 1 seul des choix a la fois: eating, thinking, sleeping
		-	il y a autant de forks que de philo (4 philo, 4 fork), mais ils doivent chacun
			en utiliser 2 pour manger
		-	quand un philo prend une fork, il faut la proteger (mutex) pour eviter
			qu'un autre s'en serve egalement
		-	quand un philo a fini de manger, il libere ses forks et start sleeping, 
			quand il se reveille, il start thinking, ensuite eating (s'il reste a manger)
		-	la simulation s'arrete quand un philo meurs
		-	un philo ne dois pas mourrir s'il reste a manger
		-	ils ne communiquent pas ensemble
		-	chaque philo ne sait pas si un autre va mourir

	regles:

		- pas de variables globales
		- args:	./philo "number_of_philosophers" "time_to_die" "time_to_eat"
						"time_to_sleep" "[number_of_times_each_philosopher_must_eat]"
				
				av[1]: 	number_of_philosophers:
							nombre de philo et de fork

				av[2]: 	time_to_die (en ms):
							si un philo n'a pas commence a manger apres
							av[2]ms, depuis le debut du dernier repas ou le debut
							de la simu, il meurt

				av[3]:	time_to_eat (en ms): 
							temps (ms) que prend un philo pour manger,
							il a besoin de 2 forks

				av[4]:	time_to_sleep (en ms):
							temps (ms) pendant lequel le philo dors

				av[5]:	number_of_times_each_philosopher_must_eat (optionnel):
							si tous les philo ont manges au moins av[5] fois,
							la simu s'arrete. si laisse vide, la simu s'arrete 
							quand un philo meurt
		
		- index des philo commence a 1
		- philo_1 est assis a cote de philo_2 et de philo_max
		  philo_n est assis a cote de philo_n+1 et philo_n-1

		- chaque philo doit etre represente par un thread different


	formattage output:

		- chaque changement de statut d'un philo doit etre formate:
		  (time = current timestamp in ms.	X philosopher number) 
		  start de 0ms

			-	time X has taken a fork
			-	time X is eating
			-	time X is sleeping
			-	time X is thinking
			-	time X died
		
		- un message ne doit pas en chevaucher un autre
		- si un philo meurt, le message doit etre affiche dans les 10ms (et fin simu)
		- pas de data races
