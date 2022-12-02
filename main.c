/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:31 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/01 12:46:01 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "philo.h"
#include "srcs/error.h" 
#include "srcs/thread.h"

pthread_t	ft_new_philo(t_args *args)
{
	pthread_t	new_philo;

	if (pthread_create(&new_philo , NULL, (void *)ft_philo, args))
		return (NULL);
	return (new_philo);
}

int	ft_create_philos(t_args *args)
{
	pthread_mutex_t	forks[args->nbr_philo];
	int	i;

	args->id = malloc(sizeof(pthread_t) * args->nbr_philo);
	if (!args->id)
		return (ft_error("malloc error"));
	i = 0;
	while (i != args->nbr_philo)
	{
		pthread_mutex_init(&forks[i++], NULL);
	}
	args->fork = forks;
	i = 0;
	while (i != args->nbr_philo)
	{
		args->id[i] = ft_new_philo(args);
		if (!args->id[i++])
			return (ft_error("can't create thread"));
	}
	i = 0;
	while (i != args->nbr_philo)
	{
		if (pthread_join(args->id[i++], NULL))
			return (ft_error("can't join"));
	}
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
}
