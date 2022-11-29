/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 08:44:48 by mmidon            #+#    #+#             */
/*   Updated: 2022/03/30 18:24:01 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!c)
		return ((char *)s + ft_strlen(s));
	i = ft_strlen(s);
	while (--i >= 0)
		if (s[i] == (char) c)
			return ((char *) s + i);
	return (NULL);
}
