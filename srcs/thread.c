/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/17 08:41:58 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <unistd.h>

#include "utils.h"
#include "../philo.h"

void	ft_usleep(int len, int end_time)
{
	///////////////////en travaux
	//struct timeval	time;

	(void)end_time;
	usleep(len);
/*	printf("len %d end %d\n", len, end_time); 
	gettimeofday(&time, NULL);
	if (!end_time)
		end_time = (int)time.tv_usec + len;
	if ((int)time.tv_usec < end_time)
	{
		usleep(len / 1000);
		ft_usleep(len, end_time);
	}*/
}

void	ft_sleep(int time, int nbr, t_args *args)
{
	ft_print(nbr, "is sleeping", args);
	ft_usleep(time, 0);
}

int	ft_eat(t_philo *philo)
{
	int	fork;

	pthread_mutex_lock(&philo->ctx->fork[philo->nbr]);
	if (philo->nbr == philo->ctx->nbr_philo - 1)
		fork = 0;
	else
		fork = philo->nbr + 1;
	pthread_mutex_lock(&philo->ctx->fork[fork]);
	pthread_mutex_lock(&philo->ctx->death);
	if (!philo->ctx->life)
		return (1);
	pthread_mutex_unlock(&philo->ctx->death);
	ft_print(philo->nbr, "is taking a fork", philo->ctx);
	ft_print(philo->nbr, "is taking a fork", philo->ctx);
	ft_print(philo->nbr, "is eating", philo->ctx);
	printf("fork %d %d \n", philo->nbr, fork); 
	ft_usleep(philo->ctx->time_to_eat, 0);
	pthread_mutex_unlock(&philo->ctx->fork[philo->nbr]);
	pthread_mutex_unlock(&philo->ctx->fork[fork]);
	pthread_mutex_lock(&philo->ctx->mutex);
	philo->lst_meal = ft_time(philo->ctx->start);
	philo->death_time = philo->lst_meal + philo->ctx->time_to_die;
	pthread_mutex_lock(&philo->ctx->death);
	if (!philo->ctx->life)
		return (1);
	pthread_mutex_unlock(&philo->ctx->death);
	pthread_mutex_unlock(&philo->ctx->mutex);
	ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
	return (0);
}

void	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->death);
	if (philo->death_time <= ft_time(philo->ctx->start))
	{
		ft_print(philo->nbr, "is dead", philo->ctx);
		philo->ctx->life = 0;
	}
	pthread_mutex_unlock(&philo->ctx->death);
}

void	ft_philo(t_philo *philo)
{
	if (philo->nbr % 2)
	{
		ft_print(philo->nbr, "is thinking", philo->ctx);
		ft_usleep(10000, 0);
	}
	while (1)
	{
	//	ft_has_eaten(philo);
		if (ft_eat(philo))
		{
			philo->ctx->life = 0;
			break;
		}
	//	ft_is_dead(philo);
		pthread_mutex_lock(&philo->ctx->death);
		philo->ctx->meal_counter++;
		if (!philo->ctx->life || philo->ctx->meal_counter == philo->ctx->max_meal)
		{
			philo->ctx->life = 0;
			pthread_mutex_unlock(&philo->ctx->death);
			break;
		}
		else
			pthread_mutex_unlock(&philo->ctx->death);
	}
}
