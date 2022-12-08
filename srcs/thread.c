/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/08 16:10:58 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <unistd.h>

#include "utils.h"
#include "../philo.h"

void	ft_usleep(int len, int end_time)
{
	struct timeval	time;

//	(void)end_time;
//	usleep(len);
//	printf("len %d end %d\n", len, end_time); 
	gettimeofday(&time, NULL);
	if (!end_time)
		end_time = (int)time.tv_usec + len;
	if ((int)time.tv_usec < end_time)
	{
		usleep(len / 1000);
		ft_usleep(len, end_time);
	}
}

void	ft_sleep(int time, int nbr, pthread_mutex_t mutex)
{
	ft_print(nbr, "is sleeping", mutex);
	ft_usleep(time, 0);
}

void	ft_eat(t_philo *philo, t_args *args)
{
	struct timeval	time;
	int	fork;

	fork = 1;
	if (philo->nbr == args->nbr_philo - 1)
		fork = - args->nbr_philo;
	pthread_mutex_lock(&args->mutex);
	pthread_mutex_lock(&args->fork[philo->nbr]);
	pthread_mutex_lock(&args->fork[philo->nbr + fork]);
	pthread_mutex_unlock(&args->mutex);
	if (!args->life)
		return ;
	ft_print(philo->nbr, "is taking a fork", args->mutex);
	ft_print(philo->nbr, "is taking a fork", args->mutex);
	if (!args->life)
		return ;
	ft_print(philo->nbr, "is eating", args->mutex);
	ft_usleep(args->time_to_eat, 0);
	
	gettimeofday(&time, NULL);
	philo->lst_meal = time.tv_usec;
	philo->death_time = philo->lst_meal + args->time_to_die;
	philo->nbr_meal++;
	
	pthread_mutex_unlock(&args->fork[philo->nbr]);
	pthread_mutex_unlock(&args->fork[philo->nbr + fork]);
	if(!args->life)
		return ;
	ft_sleep(args->time_to_sleep, philo->nbr, args->mutex);
}

void	ft_death(t_args *args)
{
	int	i;
	struct timeval	time;

	i = 0;

	while (args->id[i]->nbr_meal < args->max_meal && args->life)
	{
		gettimeofday(&time, NULL);
		if ((args->id[i]->death_time <= time.tv_usec))
		{
			pthread_mutex_lock(&args->mutex);
			args->life = 0;
			printf("\033[0;33m[%d] philo %d died\033[0m\n", time.tv_usec,i);
			pthread_mutex_unlock(&args->mutex);
			return ;
		}
		if (args->id[i]->nbr_meal >= args->max_meal)
			return ;
		i++;
		if (i >= args->nbr_philo)
			i = 0;
	}
}

void	ft_philo(t_args *args)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->nbr = args->i + 1;
	ft_eat(philo, args);
	if (!args->life)
	{
		free(philo);
		return ;
	}
	ft_print(philo->nbr, "is thinking", args->mutex);
	free(philo);
}
