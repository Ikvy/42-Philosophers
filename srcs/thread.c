/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/01 14:00:24 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <unistd.h>

#include "utils.h"
#include "../philo.h"

void	ft_usleep(int len, int end_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (!end_time)
		end_time = (int)time.tv_usec + len;
	if ((int)time.tv_usec < end_time)
	{
		usleep(len / 10);
		ft_usleep(len, end_time);
	}
}

void	ft_sleep(int time, int nbr)
{
	ft_print(nbr, "is sleeping");
	ft_usleep(time, 0);
}

void	ft_eat(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->mutex);
	ft_print(philo->nbr, "is eating");
	ft_usleep(args->time_to_eat, 0);
	pthread_mutex_unlock(&args->mutex);
}

void	ft_philo(t_args *args)
{
	printf("He's alive\n");//////////
	
	static int	nbr;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!nbr)
		nbr = 0;
	nbr++;
	philo->nbr_meal = 0;
	philo->lst_meal = 0;
	philo->nbr = nbr - 1;
	while (1)
	{
		ft_eat(philo, args);
		ft_sleep(args->time_to_sleep, philo->nbr);
	}
	printf("zoui\n");/////////////
}
