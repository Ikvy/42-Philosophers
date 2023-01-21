/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:44:25 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/21 12:11:38 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*d;

	d = (char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = c;
		i++;
	}
	b = d;
	return (b);
}
