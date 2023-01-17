/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/17 13:16:18 by mmidon           ###   ########.fr       */
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
//	printf("\n\n\neat %p %p %p\n", philo->ctx->pair, philo->ctx->death, philo->ctx->mutex); 
	pthread_mutex_lock(philo->ctx->pair);
	pthread_mutex_lock(&philo->left);
	pthread_mutex_lock(&philo->right);
	pthread_mutex_unlock(philo->ctx->pair);
//	exit(1);

	ft_print(philo->nbr, "is taking a fork", philo->ctx);
	ft_print(philo->nbr, "is taking a fork", philo->ctx);
	ft_print(philo->nbr, "is eating", philo->ctx);

	ft_usleep(philo->ctx->time_to_eat, 0);

	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(&philo->right);

	pthread_mutex_lock(philo->ctx->death);
	philo->lst_meal = ft_time(philo->ctx->start);
	philo->death_time = philo->lst_meal + philo->ctx->time_to_die;
	if (philo->ctx->life)
	{
		pthread_mutex_unlock(philo->ctx->death);
		ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
	}
	pthread_mutex_unlock(philo->ctx->death);
	return (0);
}

int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->ctx->death);
	printf("aled\n"); 
	if (philo->death_time <= ft_time(philo->ctx->start))
	{
		ft_print(philo->nbr, "is dead", philo->ctx);
		philo->ctx->life = 0;
		pthread_mutex_unlock(philo->ctx->death);
		return (1);
	}
	pthread_mutex_unlock(philo->ctx->death);
	return (0);
}

void	ft_philo(t_philo *philo)
{
	printf("PHILO %d\n", philo->nbr); 
//	printf("philo %p %p %p\n", &philo->ctx->pair, &philo->ctx->death, &philo->ctx->mutex); 
	if (philo->nbr % 2)
	{
		ft_print(philo->nbr, "is thinking", philo->ctx);
		ft_usleep(10000, 0);
	}
	while (1)
	{
		if (ft_eat(philo))
		{
			philo->ctx->life = 0;
			printf("ended\n"); 
			break;
		}
		ft_print(philo->nbr, "is thinking", philo->ctx);
		pthread_mutex_lock(philo->ctx->death);
		philo->meal_counter++;
		printf("meal %d\n", philo->meal_counter);
		printf("eat %d times\n",philo->ctx->max_meal); 
		if (!philo->ctx->life || (philo->meal_counter >= philo->ctx->max_meal))
		{
			pthread_mutex_unlock(philo->ctx->death);
			printf("%d finished\n", philo->nbr); //////////
			ft_print(philo->nbr, "is thinking", philo->ctx);
			break;
		}
		else
			pthread_mutex_unlock(philo->ctx->death);
		if (ft_is_dead(philo))
			break;
	}
}
