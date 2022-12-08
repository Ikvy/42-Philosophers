/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:58 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/08 16:12:25 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>

typedef struct
{
	pthread_t	philo;
	int	death_time;
	int	nbr_meal;
	int	lst_meal;
	int	nbr;
}		t_philo;

typedef struct
{
	int				life;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	int				i;
//	struct timeval	time;
	pthread_mutex_t	mutex;
	t_philo			**id;
	pthread_t		death;
	pthread_mutex_t	*fork;
}		t_args;

#endif
