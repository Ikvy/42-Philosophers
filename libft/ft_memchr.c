/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:13:50 by mmidon            #+#    #+#             */
/*   Updated: 2022/03/30 16:26:18 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*u;

	u = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)u[i] == (unsigned char)c)
		{
			s = u;
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
