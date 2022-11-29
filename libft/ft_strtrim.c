/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:00:33 by mmidon            #+#    #+#             */
/*   Updated: 2022/04/04 17:15:55 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;

	l = 0;
	i = 0;
	while (s1[i])
	{
		while (ft_is_set(s1[i], set))
		{
			l++;
			i++;
		}
		if (!ft_is_set(s1[i], set))
			return (l);
	}
	return (l);
}

static int	ft_mirt(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i != 0)
	{
		while (ft_is_set(s1[i], set))
			i--;
		if (!ft_is_set(s1[i], set))
			return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	zoui;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	zoui = 0;
	i = ft_trim(s1, set);
	len = ft_mirt(s1, set) - i;
	if (i == ft_strlen(s1))
		len = 0;
	dst = malloc(sizeof (char) * (len + 2));
	if (!dst)
		return (NULL);
	while (zoui <= len)
	{
		dst[zoui] = s1[i];
		zoui++;
		i++;
	}
	dst[zoui] = 0;
	return (dst);
}
