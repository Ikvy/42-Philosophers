/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/18 11:27:21 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <unistd.h>

#include "utils.h"
#include "../philo.h"

void	ft_usleep(int len, t_args *ctx)
{
	int	time;
	int	end_time;

	time = ft_time(ctx->start);
	end_time = time + len;
	while (time < end_time)
	{
		usleep(len / 1000);
		time = ft_time(ctx->start);
	}
}

void	ft_sleep(int time, int nbr, t_args *args)
{
	ft_print(nbr, "is sleeping", args);
	ft_usleep(time, args);
}

int	ft_eat(t_philo *philo)
{
	t_args *ctx;

	ctx = philo->ctx;
	pthread_mutex_lock(&philo->left);
	pthread_mutex_lock(&philo->right);
	ft_print(philo->nbr, "has taken a fork", ctx);
	ft_print(philo->nbr, "has taken a fork", ctx);
	ft_print(philo->nbr, "is eating", ctx);

	ft_usleep(philo->ctx->time_to_eat, philo->ctx);

	pthread_mutex_lock(ctx->death);
	philo->lst_meal = ft_time(ctx->start);
	philo->death_time = philo->lst_meal + ctx->time_to_die;
	philo->meal_counter++;
	pthread_mutex_unlock(ctx->death);
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(&philo->right);
	ft_sleep(philo->ctx->time_to_sleep, philo->nbr, ctx);
	return (0);
}

void	ft_death(t_args *args)
{
	int	i;

	i = 0;
	while ()
}

/*
int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->ctx->death);
	if (philo->death_time <= ft_time(philo->ctx->start))
	{
		ft_print(philo->nbr, "is dead", philo->ctx);
		philo->ctx->life = 0;
		pthread_mutex_unlock(philo->ctx->death);
		return (1);
	}
	pthread_mutex_unlock(philo->ctx->death);
	return (0);
}*/

void	ft_philo(t_philo *philo)
{
	philo->lst_meal = ft_time(philo->ctx->start);
	if (!philo->ctx->start)
		philo->ctx->start = ft_time(0);
	if (philo->nbr % 2)
	{
		ft_usleep(10, philo->ctx);
	}
	while (philo->ctx->life)
	{
		ft_eat(philo);
		if (philo->meal_counter == philo->ctx->max_meal)
			break;
		ft_print(philo->nbr, "is sleeping", philo->ctx);
	}
	if (philo->ctx->life)
		ft_print(philo->nbr, "is thinking", philo->ctx);
	else
		ft_print(philo->nbr, "is dead", philo->ctx);
}
