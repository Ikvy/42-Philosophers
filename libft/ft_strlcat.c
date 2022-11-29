/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:00:13 by mmidon            #+#    #+#             */
/*   Updated: 2022/03/31 12:54:39 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t				i;
	size_t				j;
	size_t				aled;
	size_t				oskour;

	aled = ft_strlen(dst);
	oskour = ft_strlen(src);
	i = aled;
	j = 0;
	if (dstsize > 0 && aled < dstsize - 1)
	{
		while (src[j] && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
	}
	if (aled >= dstsize)
		aled = dstsize;
	return (aled + oskour);
}
