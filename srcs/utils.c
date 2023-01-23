/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <mmidon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:55:18 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/23 13:10:27 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long int	ft_time(long long int start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec) * 1000 + (time.tv_usec) / 1000) - start);
}

void	ft_print(int nbr, char *action, t_args *args)
{
	pthread_mutex_lock(args->mutex);
	printf("\033[0;36m%lld \033[0m%d %s\n", ft_time(args->start), nbr + 1, action);
	pthread_mutex_unlock(args->mutex);
}

void	ft_usleep(int len, t_args *ctx)
{
	long long int	time;
	long long int	end_time;

	time = ft_time(ctx->start);
	end_time = time + len;
	while (ft_time(ctx->start) < end_time)
	{
		pthread_mutex_lock(ctx->death);
		if (!ctx->life)
		{
			pthread_mutex_unlock(ctx->death);
			break ;
		}
		pthread_mutex_unlock(ctx->death);
		usleep(50);
	}
}

void	ft_is_it_the_end(t_philo *philo, int *life)
{
	pthread_mutex_lock(philo->ctx->death);
	*life = philo->ctx->life;
	pthread_mutex_unlock(philo->ctx->death);
}

void	ft_wait(t_philo *philo)
{
	if (philo->nbr % 2)
	{
		ft_print(philo->nbr, "is thinking", philo->ctx);
		ft_usleep(10, philo->ctx);
	}
}
