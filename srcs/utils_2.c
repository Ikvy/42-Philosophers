/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:35:32 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/24 09:18:00 by mmidon           ###   ########.fr       */
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

int	ft_str_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	ft_parse(char **av)
{
	if (!ft_str_isdigit(av[1]) || !ft_str_isdigit(av[2])
		|| !ft_str_isdigit(av[3]) || !ft_str_isdigit(av[4]))
		return (ft_error("invalid format. [digit only !]"));
	return (0);
}

int	ft_check_after_atoi(t_args *args)
{
	if (args->time_to_eat < 1)
		return (ft_error("please, be consistent."));
	if (args->time_to_sleep < 1)
		return (ft_error("please, be consistent."));
	if (args->max_meal == 0)
		return (1);
	return (0);
}
