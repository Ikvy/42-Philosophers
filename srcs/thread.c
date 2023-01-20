/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/20 09:21:35 by mmidon           ###   ########.fr       */
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

void	ft_sleep(long long int time, int nbr, t_args *args)
{
	ft_print(nbr, "is sleeping", args);
	ft_usleep(time, args);
}

int	ft_eat(t_philo *philo)
{
	t_args *ctx;

	ctx = philo->ctx;
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->ctx->death);
	if (!philo->ctx->life)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->ctx->death);
		return (1);
	}
	pthread_mutex_unlock(philo->ctx->death);
	ft_print(philo->nbr, "has taken a fork", ctx);
	ft_print(philo->nbr, "has taken a fork", ctx);
	ft_print(philo->nbr, "is eating", ctx);
	ft_usleep(philo->ctx->time_to_eat, philo->ctx);
	pthread_mutex_lock(ctx->death);
	philo->lst_meal = ft_time(ctx->start);
	philo->death_time = philo->lst_meal + ctx->time_to_die;
	philo->meal_counter++;
	pthread_mutex_unlock(ctx->death);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (0);
}

void	ft_death(t_args *args)
{
	int	i;
	long long int	cur_time;

	i = -1;
	while (args->id[++i] && args->life)
	{
		pthread_mutex_lock(args->death);
		cur_time = ft_time(args->start);
		if (args->id[i]->death_time <= cur_time)
		{
			args->life = 0;
			ft_print(args->id[i]->nbr, "is dead", args);
		}
		pthread_mutex_unlock(args->death);
		if (i >= args->nbr_philo - 1)
			i = -1;
	}
}

void	ft_philo(t_philo *philo)
{
	int	life;

	life = 1;
	if (!philo->ctx->start)
		philo->ctx->start = ft_time(0);
	philo->lst_meal = ft_time(philo->ctx->start);
	philo->death_time = philo->lst_meal + philo->ctx->time_to_die;
	if (philo->nbr % 2)
	{
		ft_print(philo->nbr,"is thinking",philo->ctx);
		ft_usleep(10, philo->ctx);
	}
	while (life)
	{
		ft_eat(philo);

		pthread_mutex_lock(philo->ctx->death);
		life = philo->ctx->life;
		if (philo->ctx->life)
		{
			pthread_mutex_unlock(philo->ctx->death);
			ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
		}
		else
			pthread_mutex_unlock(philo->ctx->death);
		if (philo->meal_counter == philo->ctx->max_meal)
			break;
	}
	if (philo->ctx->life)
		ft_print(philo->nbr, "is thinking", philo->ctx);
}
