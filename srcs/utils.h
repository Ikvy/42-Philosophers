/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <mmidon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:36:36 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/23 13:43:02 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>

# include "../philo.h"

int				ft_check_fork(t_philo *philo);
void			ft_print(int nbr, char *action, t_args *args);
long long int	ft_time(int start);
void			ft_death(t_args *args);
void			ft_usleep(int len, t_args *ctx);
void			ft_wait(t_philo *philo, int *life);
void			ft_is_it_the_end(t_philo *philo, int *life);

#endif
