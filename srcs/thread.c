/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/21 11:59:16 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <unistd.h>

#include "utils.h"
#include "../philo.h"

void	ft_usleep(int len, t_args *ctx)
{
	long long int	time;
	long long int	end_time;

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
	pthread_mutex_lock(philo->ctx->death);
	if (philo->ctx->life)
	{
		pthread_mutex_lock(philo->left);
		ft_print(philo->nbr, "has taken a fork", philo->ctx);
	}
	if (!philo->ctx->life)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->ctx->death);
		return (1);
	}
	pthread_mutex_lock(philo->right);
	ft_print(philo->nbr, "has taken a fork", philo->ctx);
	ft_print(philo->nbr, "is eating", philo->ctx);
	philo->lst_meal = ft_time(0) - philo->ctx->start;
	philo->ctx->id[philo->nbr].death_time = ft_time(0) - philo->ctx->start
		+ philo->ctx->time_to_die;
	philo->meal_counter++;
	pthread_mutex_unlock(philo->ctx->death);
	ft_usleep(philo->ctx->time_to_eat, philo->ctx);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (0);
}

void	ft_death(t_args *args)
{
	int	i;
	int	all_ate;
	int	life;

	i = 0;
	pthread_mutex_lock(args->death);
	all_ate = args->all_ate;
	life = args->life;
	pthread_mutex_unlock(args->death);
	while (life && !all_ate)
	{
		pthread_mutex_lock(args->death);
		if (args->id[i].death_time <= ft_time(0) - args->start)
		{
			args->life = 0;
			ft_print(args->id[i].nbr, "is dead", args);
		}
		life = args->life;
		all_ate = args->all_ate;
		pthread_mutex_unlock(args->death);
		i++;
		if (i >= args->nbr_philo - 1)
			i = 0;
	}
}

void	ft_is_it_the_end(t_philo *philo, int *life)
{
	pthread_mutex_lock(philo->ctx->death);
	*life = philo->ctx->life;
	if (philo->ctx->life)
	{
		pthread_mutex_unlock(philo->ctx->death);
		ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
	}
	else
		pthread_mutex_unlock(philo->ctx->death);
}

void	ft_philo(t_philo *philo)
{
	int	life;

	life = 1;
	philo->lst_meal = 0;
	philo->death_time = philo->lst_meal + philo->ctx->time_to_die;
	if (philo->nbr % 2)
	{
		ft_print(philo->nbr, "is thinking", philo->ctx);
		ft_usleep(10, philo->ctx);
	}
	while (life)
	{
		if (ft_eat(philo))
			return ;
		ft_is_it_the_end(philo, &life);
		if (philo->meal_counter == philo->ctx->max_meal)
			break ;
	}
	pthread_mutex_lock(philo->ctx->death);
	if (philo->ctx->life)
		ft_print(philo->nbr, "is thinking", philo->ctx);
	pthread_mutex_unlock(philo->ctx->death);
}
