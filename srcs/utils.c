/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:55:18 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/18 09:39:05 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "../philo.h"

int	ft_time(int start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec - start);
}

void	ft_print(int nbr, char *action,  t_args *args)
{
	pthread_mutex_lock(args->mutex);
	printf("\033[0;36m%d \033[0m%d %s\n", ft_time(args->start), nbr + 1, action); //////// nbr + 1
	pthread_mutex_unlock(args->mutex);
}
