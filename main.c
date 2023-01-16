/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:31 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/16 12:12:41 by mmidon           ###   ########.fr       */
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
	struct	timeval	time;

//	philo = malloc(sizeof(t_philo));
	gettimeofday(&time, NULL);
	philo.lst_meal = time.tv_usec;
	philo.death_time = philo.lst_meal + args->time_to_die;
	philo.nbr = nbr;
	philo.meal_counter = 0;
	philo.ctx = args;
	pthread_mutex_init(&args->fork[nbr], NULL);
	if (pthread_create(&args->id[nbr].philo , NULL, (void *)ft_philo, &philo))
		return (philo);
	return (philo);
}

int	ft_join(t_args *args)
{
	int	i;

	i = args->nbr_philo - 1;
	while (i)
	{
		printf("to join %d\n",i); 
		if (pthread_join(args->id[i].philo, NULL))
			return (ft_error("can't join"));
		i--;
	}
	return (0);
}

/*int	ft_forks(t_args *args)
{
	int	i;

	args->fork = malloc(sizeof(pthread_t) * args->nbr_philo);
	i = 0;
	while (i != args->nbr_philo - 1)
	{
		if (pthread_mutex_init(&args->fork[i++], NULL))
			return (ft_error("fork thread"));
	}
	return (0);
}*/

int	ft_create_philos(t_args *args)
{
	int	i;

	i = 0;
	args->id = malloc(sizeof(t_philo *) * args->nbr_philo);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->nbr_philo);
	args->life = 1;
	if (!args->max_meal)
		args->max_meal = -1;
	i = 0;
	while (i < args->nbr_philo)
	{
		if(!(i % 2))
			ft_new_philo(args, i);
		i++;
	}
	i = 0;
	while (i < args->nbr_philo)
	{
		if(i % 2)
			ft_new_philo(args, i);
		i++;
	}
	ft_join(args);
	return (0);
}

int	ft_init(t_args *args, char **av)
{
	args->nbr_philo = ft_atoi(av[1]);
	if (args->nbr_philo <= 1)
		return(ft_error("not enough philosophers"));
	pthread_mutex_init(&args->mutex, NULL);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->max_meal = ft_atoi(av[5]);
	ft_create_philos(args);
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
