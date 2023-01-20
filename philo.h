/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:58 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/20 09:01:06 by mmidon           ###   ########.fr       */
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

struct	s_args;

typedef struct s_philo
{
	pthread_t	philo;
	long long int death_time;
	int	lst_meal;
	int	meal_counter;
	int	nbr;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*death;
	struct s_args	*ctx;
}		t_philo;

typedef struct	s_args
{
	int				life;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	long long int	start;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*death;
	t_philo			**id;
}		t_args;

#endif
