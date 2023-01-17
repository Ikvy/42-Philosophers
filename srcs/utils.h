/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:36:36 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/17 08:32:09 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "../philo.h"

#ifndef UTILS_H
# define UTILS_H

void    ft_print(int nbr, char *action, t_args *args);
int		ft_time(int start);
//void    ft_link(t_philo *philo, int nbr);

#endif
