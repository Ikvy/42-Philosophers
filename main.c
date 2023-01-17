/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:31 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/17 09:55:33 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "philo.h"
#include "srcs/error.h"
#include "srcs/utils.h" 
#include "srcs/thread.h"

t_philo	ft_new_philo(t_args *args, int nbr)
{
	t_philo			philo;

	philo.lst_meal = ft_time(args->start);
	philo.death_time = philo.lst_meal + args->time_to_die;
	philo.nbr = nbr;
	philo.ctx = args;
	philo.left = args->fork[nbr];
	if (nbr == args->nbr_philo)
	{
		philo.right = args->fork[0];
		printf("fork %d %d\n", nbr, 0);
	}
	else
	{
		printf("fork %d %d\n", nbr, nbr + 1);
		philo.right = args->fork[nbr + 1];
	}
	pthread_create(&args->id[nbr].philo , NULL, (void *)ft_philo, &philo);
	printf("thread %d\n", nbr);
	return (philo);
}

int	ft_join(t_args *args)
{
	int	i;

	i = -1;
	printf("nbr philos %d\n", args->nbr_philo); 
	while (++i < args->nbr_philo)
	{
		printf("to be joined %d\n",i);
		if (pthread_join(args->id[i].philo, NULL))
			return (ft_error("can't join"));
		printf("joined %d\n",i);
	}
	i = -1;
	while (++i < args->nbr_philo)
	{
		pthread_mutex_destroy(&args->fork[i]);
	}
	printf("death\n"); 
//	pthread_mutex_destroy(&args->death); //////////////bordel de ses morts
	printf("mutex\n"); 
	pthread_mutex_destroy(&args->mutex);
	pthread_mutex_destroy(&args->pair);
	return (0);
}

int	ft_create_philos(t_args *args)
{
	int	i;

	i = 0;
	args->id = malloc(sizeof(t_philo *) * args->nbr_philo);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->nbr_philo);
	args->life = 1;
	if (!args->max_meal)
		args->max_meal = -1;
	i = -1;
	while (++i < args->nbr_philo)
		pthread_mutex_init(&args->fork[i], NULL);
	i = -1;
	while (++i < args->nbr_philo)
			ft_new_philo(args, i);
	if (args->nbr_philo % 2)
		ft_print(args->nbr_philo, "is thinking", args);
	ft_join(args);
	return (0);
}

int	ft_init(t_args *args, char **av)
{
	args->nbr_philo = ft_atoi(av[1]);
	if (args->nbr_philo <= 1)
		return(ft_error("not enough philosophers"));
	pthread_mutex_init(&args->mutex, NULL);
	pthread_mutex_init(&args->pair, NULL);
	pthread_mutex_init(&args->death, NULL);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->max_meal = ft_atoi(av[5]);
	args->meal_counter = 0;
	ft_create_philos(args);
	args->start = ft_time(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac > 6 || ac <= 4)
		return (ft_error("Wrong number of arguments"));
	if (ft_init(&args, av))
		return (1);
	pthread_mutex_destroy(&args.mutex);
	//system("leaks philo"); 
}
