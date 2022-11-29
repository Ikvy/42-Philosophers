/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:27:20 by mmidon            #+#    #+#             */
/*   Updated: 2022/04/11 14:02:11 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_cmpt(char const *s, char c)
{
	size_t	i;
	size_t	cmpt;

	i = 0;
	cmpt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			cmpt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cmpt);
}

static char	*ft_charcpy(char const *s, char c)
{
	char	*cpy;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	cpy = malloc((len + 1) * sizeof(*cpy));
	if (!cpy)
		return (NULL);
	while (s[i] && i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	x;

	i = 0;
	if (!s)
		return (NULL);
	array = malloc(((ft_cmpt(s, c)) + 1) * sizeof(*array));
	if (!array)
		return (NULL);
	x = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[x++] = ft_charcpy(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	array[x] = NULL;
	return (array);
}
