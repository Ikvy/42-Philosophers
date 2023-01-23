/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:03:58 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/23 08:20:50 by mmidon           ###   ########.fr       */
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

struct	s_args;

typedef struct s_philo
{
	int				my_life;
	pthread_t		philo;
	long long int	death_time;
	long long int	lst_meal;
	int				meal_counter;
	int				nbr;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_args	*ctx;
}		t_philo;

typedef struct s_args
{
	int				has_eaten;
	int				life;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	int				all_ate;
	long long int	start;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*death;
	pthread_mutex_t	*hunger;
	t_philo			*id;
}		t_args;

void	ft_death(t_args *args);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
#endif
