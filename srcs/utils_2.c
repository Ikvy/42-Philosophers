/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:35:32 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/23 13:38:34 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include "utils.h" 

int	ft_check_fork(t_philo *philo)
{
	if (!philo->right)
	{
		ft_usleep(philo->ctx->time_to_die, philo->ctx);
		return (1);
	}
	return (0);
}
