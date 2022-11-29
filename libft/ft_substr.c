/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:25:06 by mmidon            #+#    #+#             */
/*   Updated: 2022/04/04 15:17:14 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	norminette_de_ses_morts(size_t zouii, char *s,
		unsigned int start, size_t len)
{
	if (start < ft_strlen(s))
		zouii = ft_strlen(s) - start;
	if (zouii > len)
		zouii = len;
	return (zouii);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;
	size_t			zouii;

	if (!s)
		return (NULL);
	zouii = 0;
	zouii = norminette_de_ses_morts(zouii, s, start, len);
	i = 0;
	j = 0;
	sub = malloc(sizeof (char) * (zouii + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (j < zouii && i >= start)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}
