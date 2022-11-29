/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:54:15 by mmidon            #+#    #+#             */
/*   Updated: 2022/04/06 10:43:24 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_rev(char *dest)
{
	size_t	len;
	size_t	i;
	char	temp;

	i = 0;
	len = ft_strlen(dest);
	while (i < len / 2)
	{
		temp = dest[i];
		dest[i] = dest[len - i - 1];
		dest[len - i - 1] = temp;
		i++;
	}
}

int	ft_norminette(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	i;
	int		x;

	x = (n < 0);
	i = 0;
	dest = ft_calloc(11 + x, sizeof(char));
	if (!dest)
		return (0);
	if (n == 0)
		dest[0] = '0';
	if (x)
		n *= -1;
	while (n != 0)
	{
		dest[i++] = ft_norminette(n % 10) + '0';
		n = n / 10;
	}
	if (x)
		dest[i] = '-';
	ft_rev(dest);
	return (dest);
}
