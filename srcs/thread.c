/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/18 08:03:08 by mmidon           ###   ########.fr       */
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
	t_args *ctx;

	ctx = philo->ctx;
//	printf("PHILO eat %d\n", philo->nbr); 
//	pthread_mutex_lock(philo->pair);
	pthread_mutex_lock(&philo->left);
//	printf("\n\n\neat %p\n",ctx->death); 
	ft_print(philo->nbr, "is taking a fork", ctx);
	pthread_mutex_lock(&philo->right);
	ft_print(philo->nbr, "is taking a fork", ctx);
//	pthread_mutex_unlock(philo->pair);

	ft_print(philo->nbr, "is eating", ctx);

	ft_usleep(philo->ctx->time_to_eat, 0);

	printf("aled\n"); 
	pthread_mutex_lock(ctx->death);
	philo->lst_meal = ft_time(ctx->start);
	philo->death_time = philo->lst_meal + ctx->time_to_die;
	philo->meal_counter++;
	pthread_mutex_unlock(ctx->death);
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(&philo->right);
	ft_sleep(philo->ctx->time_to_sleep, philo->nbr, ctx);
//	if (philo->ctx->life)
//	{
//	}
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

	int	nbr;

	nbr = philo->nbr;
	printf("PHILO %d\n", philo->nbr); 
	printf("NBR %d\n", nbr); 
//	printf("philo %p %p %p\n", &philo->ctx->pair, &philo->ctx->death, &philo->ctx->mutex); 
/*	if (philo->nbr == 1)
	{
		ft_print(philo->nbr, "is thinking (waiting)", philo->ctx); ////////////
		usleep(20000);
	}*/
	printf("PHILObis %d\n", philo->nbr); 
	printf("NBR %d\n", nbr); 
	while (philo->ctx->life)
	{
		ft_eat(philo);
		if (philo->meal_counter == philo->ctx->max_meal)
		{
			philo->ctx->life = 0;
			printf("ended\n"); 
			break;
		}
		ft_print(philo->nbr, "is sleeping", philo->ctx);
	}
}
