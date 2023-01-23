/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <mmidon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/23 13:09:13 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "utils.h"
#include "../philo.h"

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
	philo->ctx->id[philo->nbr].death_time = ft_time(0) - philo->ctx->start
		+ philo->ctx->time_to_die;
	pthread_mutex_unlock(philo->ctx->hunger);
	ft_usleep(philo->ctx->time_to_eat, philo->ctx);
	philo->meal_counter++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (0);
}

void	ft_dead(t_args *args, int i)
{
	pthread_mutex_lock(args->death);
	args->life = 0;
	ft_print(args->id[i].nbr, "died", args);
	pthread_mutex_unlock(args->death);
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
		pthread_mutex_lock(args->hunger);
		if (args->id[i].death_time <= ft_time(0) - args->start)
			ft_dead(args, i);
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

void	ft_philo(t_philo *philo)
{
	int	life;

	life = 1;
	philo->lst_meal = 0;
	philo->death_time = philo->lst_meal + philo->ctx->time_to_die;
	ft_wait(philo);
	while (life)
	{
		ft_eat(philo);
		ft_is_it_the_end(philo, &life);
		if (philo->meal_counter == philo->ctx->max_meal && life)
		{
			ft_print(philo->nbr, "is thinking", philo->ctx);
			break ;
		}
		if (life)
			ft_sleep(philo->ctx->time_to_sleep, philo->nbr, philo->ctx);
		pthread_mutex_lock(philo->ctx->death);
		if (philo->ctx->life)
			ft_print(philo->nbr, "is thinking", philo->ctx);
		pthread_mutex_unlock(philo->ctx->death);
		ft_is_it_the_end(philo, &life);
	}
	free(philo);
}
