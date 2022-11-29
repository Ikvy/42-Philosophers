/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:11:35 by mmidon            #+#    #+#             */
/*   Updated: 2022/11/29 11:56:53 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <unistd.h>

#include "../philo.h"

void	ft_eat(t_philo *philo, t_args args)
{
	ft_usleep(args->time_to_eat)
}

void	ft_philo(t_args args)
{
	printf("He's alive\n");//////////
	
	static	nbr;
	t_philo	*philo;

	if (!nbr)
		nbr = 0;
	nbr++;
	philo->nbr_meal = 0;
	philo->lst_meal = 0;
	philo->nbr = nbr - 1;
	while (1)
	{
		ft_eat(philo, args);
		ft_sleep(args->time_to_sleep);
		ft_think();
	}
	printf("zoui\n");/////////////
}
