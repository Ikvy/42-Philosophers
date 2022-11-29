/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:58 by mmidon            #+#    #+#             */
/*   Updated: 2022/11/29 09:19:08 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>

typedef struct
{
	int	available;
	int	nbr;
}		t_fork;

typedef struct
{
	int	nbr_meal;
	int	lst_meal;
	int	nbr;
	t_fork	right;
	t_fork	left;
}		t_philo;

typedef struct
{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meal;
	pthread_t *id;
}		t_args;

int		ft_atoi(char *str);

#endif
