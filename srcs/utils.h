/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:36:36 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/18 10:00:02 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "../philo.h"

#ifndef UTILS_H
# define UTILS_H

void    ft_print(int nbr, char *action, t_args *args);
int		ft_time(int start);
void    ft_death(t_args *args);

#endif
