/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:55:18 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/17 13:36:19 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>

#include "../philo.h"

/*void	ft_remake(t_args *args, int added)
{
	int	new_size;
	t_philo	**new_ids;
	int	i;
	
	i = -1;
	new_size = ft_strlen_tab(args->id) + added;
	new_ids = malloc(sizeof(t_philo *) * new_size);


}

void	ft_link(t_philo *philo, int nbr)
{
	int	i;
	t_philo	*ptr;
	t_philo	*prev;
	t_philo	*next;

	ptr = &philo[0];
	i = -1;
	while (++i < nbr)
	{
		printf("\ni %d\n", philo->nbr); 
		printf("\ni %d\n", i); 
		printf("cur %p\n", philo); 
		printf("cur %p\n", &philo[i]); 
		next = &philo[i + 1];
		if (i)
			philo->prev = prev;
		if (&philo[i + 1])
		{
			printf("next %p\n", next); 
			philo->next = next;
			printf("next %p\n", philo->next); 
			prev = &philo[i];
			philo = philo->next;
		}
		else
			prev = &philo[i];
		printf("aded3\n"); 
	}
	philo = ptr;
}*/

int	ft_time(int start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec - start);
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

void	ft_print(int nbr, char *action,  t_args *args)
{
	pthread_mutex_lock(args->mutex);
	printf("\033[0;36m[%d] \033[0m philo %d %s\n", ft_time(args->start), nbr, action); //////// nbr + 1
	pthread_mutex_unlock(args->mutex);
}
