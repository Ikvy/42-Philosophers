/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:20:12 by mmidon            #+#    #+#             */
/*   Updated: 2023/01/21 12:08:39 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *)malloc (size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
