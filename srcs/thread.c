/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/16 11:31:29 by mmidon           ###   ########.fr       */
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

void	ft_eat(t_philo *philo)
{
	struct timeval	time;
	int	fork;

	pthread_mutex_lock(&philo->ctx->mutex);
	pthread_mutex_lock(&philo->ctx->fork[philo->nbr]);
	printf("aled %d\n", philo->nbr); 
	if (philo->nbr == philo->ctx->nbr_philo - 1)
		fork = 0;
	else
		fork = philo->nbr + 1;
	pthread_mutex_lock(&philo->ctx->fork[fork]);
	pthread_mutex_unlock(&philo->ctx->mutex);
	if (!philo->ctx->life)
		return ;
	ft_print(philo->nbr, "is taking a fork", philo->ctx->mutex);
	ft_print(philo->nbr, "is taking a fork", philo->ctx->mutex);
	if (!philo->ctx->life)
		return ;
	ft_print(philo->nbr, "is eating", philo->ctx->mutex);
	ft_usleep(philo->ctx->time_to_eat, 0);
	pthread_mutex_unlock(&philo->ctx->fork[philo->nbr]);
	pthread_mutex_unlock(&philo->ctx->fork[fork]);
	gettimeofday(&time, NULL);
	philo->lst_meal = time.tv_usec;
	philo->death_time = philo->lst_meal + philo->ctx->time_to_die;
	philo->meal_counter++;
	if (!philo->ctx->life)
		return ;
	ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx->mutex);
}

void	ft_death(t_philo *philo)
{
	ft_print(philo->nbr, "is dead", philo->ctx->death);

}

void	ft_has_eaten(t_philo *philo)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	if (philo->death_time >= time.tv_usec)
		philo->ctx->life = 0;
}

void	ft_philo(t_philo *philo)
{
	printf("PHILO %d\n", philo->nbr); 
	while (philo->meal_counter < philo->ctx->max_meal)
	{
		if (philo->ctx->life)
		{
			ft_print(philo->nbr, "is thinking", philo->ctx->mutex);
			ft_eat(philo);
			ft_has_eaten(philo);
		}
		if (!philo->ctx->life)
		{
			ft_death(philo);
			break;
		}
	}	
}
