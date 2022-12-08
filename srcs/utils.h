/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:36:36 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/02 08:55:26 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#ifndef UTILS_H
# define UTILS_H

void    ft_print(int nbr, char *action, pthread_mutex_t mutex);

#endif
