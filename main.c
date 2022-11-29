/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:31 by mmidon            #+#    #+#             */
/*   Updated: 2022/11/29 09:14:45 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include "srcs/error.h" 
#include "srcs/thread.h"

pthread_t	ft_new_philo(t_args *args)
{
	pthread_t	new_philo;
	//int	ret;

	(void)args;
	pthread_create(&new_philo , NULL, (void *)ft_philo, args);
	return(new_philo);
	/*if (!ret)
	{

	}*/
}

int	ft_create_philos(t_args *args)
{
	//pthread_t	*id;
	int	i;

	args->id = malloc(sizeof(pthread_t) * args->nbr_philo);
	if (!args->id)
		return (ft_error("malloc error"));
	i = 0;
	while (i != args->nbr_philo)
	{
		args->id[i] = ft_new_philo(args);
		i++;
	}
	return (0);
}

int	ft_init(t_args *args, char **av)
{
	args->nbr_philo = ft_atoi(av[1]);
	if (!args->nbr_philo)
		return(ft_error("no philosophers"));
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
}
