/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:31 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/21 11:47:18 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "philo.h"
#include "srcs/error.h"
#include "srcs/utils.h" 
#include "srcs/thread.h"

void	ft_new_philo(t_args *args, int nbr)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
//	args->id[nbr] = malloc(sizeof(t_philo));
	philo->nbr = nbr;
	philo->ctx = args;
	philo->meal_counter = 0;
	philo->left = &args->fork[nbr];
	philo->mutex = args->mutex;
	philo->death = args->death;
	if (nbr == args->nbr_philo - 1)
		philo->right = &args->fork[0];
	else
		philo->right = &args->fork[nbr + 1];
	args->id[nbr].death_time = args->time_to_die;
	pthread_create(&(args->id[nbr].philo) , NULL, (void *)ft_philo, philo);
}

int	ft_join(t_args *args, pthread_t death)
{
	int	i;

	i = -1;
	while (++i < args->nbr_philo)
	{
		pthread_join(args->id[i].philo, NULL);
	}
	pthread_mutex_lock(args->death);
	args->all_ate = 1;
	pthread_mutex_unlock(args->death);
	pthread_join(death, NULL);
	i = -1;
	while (++i < args->nbr_philo)
		pthread_mutex_destroy(&args->fork[i]);
	pthread_mutex_destroy(args->death);
	pthread_mutex_destroy(args->mutex);
	return (0);
}

int	ft_create_philos(t_args *args)
{
	int	i;
	pthread_t	*death;

	i = 0;
	death = malloc(sizeof(pthread_t));
	args->id = ft_calloc(sizeof(t_philo) , args->nbr_philo);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->nbr_philo);
	i = -1;
	while (++i < args->nbr_philo)
		pthread_mutex_init(&args->fork[i], NULL);
	i = -1;
	args->start = ft_time(0);
	while (++i < args->nbr_philo)
			ft_new_philo(args, i);
	pthread_create(death , NULL, (void *)ft_death, args);
	//ft_death(args); ////////aled
	ft_join(args, *death);
	return (0);
}

int	ft_init(t_args *args, char **av)
{
	args->nbr_philo = ft_atoi(av[1]);
	if (args->nbr_philo < 1) ////////////////////////// 1
		return(ft_error("not enough philosophers"));
	args->mutex = malloc(sizeof(pthread_mutex_t));
	args->death = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(args->mutex, NULL);
	pthread_mutex_init(args->death, NULL);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->start = 0;
	args->all_ate = 0;
	args->life = 1;
	args->max_meal = 0;
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
	//system("leaks philo"); 
}
