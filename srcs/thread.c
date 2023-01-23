/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/23 09:15:00 by mmidon           ###   ########.fr       */
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
	while (ft_time(ctx->start) < end_time)
	{
		usleep(50);
	}
}

void	ft_sleep(long long int time, int nbr, t_args *args)
{
	ft_print(nbr, "is sleeping", args);
	ft_usleep(time, args);
}

int	ft_eat(t_philo *philo)
{
	int	life;

	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->ctx->death);
	life = philo->ctx->life;
	pthread_mutex_unlock(philo->ctx->death);
	if (life)
	{
		ft_print(philo->nbr, "has taken a fork", philo->ctx);
		ft_print(philo->nbr, "has taken a fork", philo->ctx);
		ft_print(philo->nbr, "is eating", philo->ctx);
	}
	pthread_mutex_lock(philo->ctx->hunger);
	ft_print(philo->nbr, "has locked hunger", philo->ctx);
	//philo->lst_meal = ft_time(0) - philo->ctx->start;
	philo->ctx->id[philo->nbr].death_time = ft_time(0) - philo->ctx->start
		+ philo->ctx->time_to_die;
	philo->meal_counter++;
	pthread_mutex_unlock(philo->ctx->hunger);
	ft_usleep(philo->ctx->time_to_eat, philo->ctx);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
//	ft_print(philo->nbr ,"locked death to sleep\n", philo->ctx);
/*	pthread_mutex_lock(philo->ctx->death);
	life = philo->ctx->life;
	pthread_mutex_unlock(philo->ctx->death);
*/	if (life)
	{
		ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
	}
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
	//	ft_usleep(10, args);
		pthread_mutex_lock(args->hunger);
		if (args->id[i].death_time <= ft_time(0) - args->start)
		{
			pthread_mutex_lock(args->death);
			args->life = 0;
			ft_print(args->id[i].nbr, "is dead", args);
			pthread_mutex_unlock(args->death);
		}
		pthread_mutex_lock(args->death);
		life = args->life;
		pthread_mutex_unlock(args->death);
		all_ate = args->all_ate;
		pthread_mutex_unlock(args->hunger);
		i++;
		if (i >= args->nbr_philo - 1)
			i = 0;
	}
}

void	ft_is_it_the_end(t_philo *philo)
{
	pthread_mutex_lock(philo->ctx->death);
//	ft_print(philo->nbr, "is having mutex death locked to sleep", philo->ctx);
	philo->my_life = philo->ctx->life;
	pthread_mutex_unlock(philo->ctx->death);////////
/*	if (philo->ctx->life)
	{
		pthread_mutex_unlock(philo->ctx->death);
		ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
	}
	else
		pthread_mutex_unlock(philo->ctx->death);*/
}

void	ft_philo(t_philo *philo)
{
	ft_print(philo->nbr ,"is alive\n", philo->ctx);
	if (philo->nbr % 2 /*|| (philo->ctx->nbr_philo % 2 && philo->ctx->nbr_philo - 1 == philo->nbr)*/)
	{
		ft_print(philo->nbr, "is thinking", philo->ctx);
		ft_usleep(100, philo->ctx);
	}
	philo->lst_meal = 0;
	philo->death_time = philo->ctx->time_to_die;
	while (philo->my_life)
	{
		if (ft_eat(philo))
			philo->my_life = 0;
		if (philo->meal_counter == philo->ctx->max_meal)
		{
			philo->ctx->has_eaten++;
			break ;
		}
		ft_is_it_the_end(philo);
		if (philo->my_life)
			ft_print(philo->nbr, "is thinking", philo->ctx);
	}
	free(philo);
}
