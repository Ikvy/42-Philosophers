/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:36:11 by mmidon            #+#    #+#             */
/*   Updated: 2022/07/15 11:10:10 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		dest [i] = dest[i] - dest[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*cp;

	cp = malloc (sizeof(char) * (ft_strlen(src) + 1));
	if (!cp)
		return (NULL);
	cp = ft_strcpy(cp, src);
	return (cp);
}
