/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:31 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/08 16:16:25 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "philo.h"
#include "srcs/error.h" 
#include "srcs/thread.h"

t_philo		*ft_new_philo(t_args *args)
{
	t_philo		*philo;
	struct	timeval	time;

	philo = malloc(sizeof(t_philo));
	gettimeofday(&time, NULL);
	philo->lst_meal = time.tv_usec;
	philo->death_time = philo->lst_meal + args->time_to_die;
	philo->nbr_meal = 0;
	if (pthread_create(&philo->philo , NULL, (void *)ft_philo, args))
		return (NULL);
	return (philo);
}

int	ft_join(t_args *args)
{
	int	i;

	i = 0;
	while (i != args->nbr_philo - 1)
	{
		if (pthread_join(args->id[i++]->philo, NULL))
			return (ft_error("can't join"));
	}
	return (0);
}

void	ft_impair(t_args *args)
{
	ft_remake(args, 1);
	args->i = args->nbr_philo - 1;
	args->id[args->nbr_philo - 1] = ft_new_philo(args);
}

int	ft_forks(t_args *args)
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
}

int	ft_create_philos(t_args *args)
{
	int	meal_counter;

	meal_counter = 0;
	if (!args->id)
		return (ft_error("malloc error"));
	args->life = 1;
	if (!args->max_meal)
		args->max_meal = -1;
	ft_forks(args);
	printf(" %d philos \n", args->nbr_philo);
	pthread_create(&args->death, NULL, (void *)ft_death, args);
	while (meal_counter != args->max_meal && args->life)
	{
		if (args->nbr_philo % 2 && args->life)
			ft_impair(args);
		args->i = 0;
		while (args->i < args->nbr_philo - args->nbr_philo % 2 && args->life)
		{
			if(!(args->i % 2))
				args->id[args->i] = ft_new_philo(args);
			args->i++;
		}
		args->i = 0;
		while (args->i < args->nbr_philo - args->nbr_philo % 2 && args->life)
		{
			if(args->i % 2)
				args->id[args->i] = ft_new_philo(args);
			args->i++;
		}
		meal_counter++;
	}
	ft_join(args);
	free(args->id);
//	free(args->fork);
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
