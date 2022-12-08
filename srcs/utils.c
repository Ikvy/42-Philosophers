/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:55:18 by mmidon            #+#    #+#             */
/*   Updated: 2022/12/08 16:40:48 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "../philo.h"

void	ft_remake(t_args *args, int added)
{
	int	new_size;
	

	new_size = ft_strlen_tab(args->id) + added;


}

int	ft_strlen_tab(void *tab)
{
	int	i;

	i = -1;
	if (!tab)
		return (0);
	while (&tab[++i])
		;
	return (1);
}

void	ft_print(int nbr, char *action,  pthread_mutex_t mutex)
{
	struct timeval time;

	(void)mutex;	
	//pthread_mutex_lock(&mutex);
	gettimeofday(&time, NULL);
	printf("\033[0;36m[%d] \033[0m philo %d %s\n", time.tv_usec, nbr, action);
	//pthread_mutex_unlock(&mutex);
}
