/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:36:36 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/21 12:01:38 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>

# include "../philo.h"

void			ft_print(int nbr, char *action, t_args *args);
long long int	ft_time(int start);
void			ft_death(t_args *args);

#endif
