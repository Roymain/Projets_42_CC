/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:51:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 20:00:31 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*crea(int m, char *s, int i)
{
	if (m >= 10)
	{
		i--;
		s[i] = (m % 10) + '0';
		crea(m / 10, s, i);
	}
	else if (m < 10)
	{
		i--;
		s[i] = (m + '0');
	}
	return (s);
}

static int	count(long long int o)
{
	int	i;

	i = 2;
	if (o < 0)
	{
		i++;
		o *= -1;
	}
	while (o >= 10)
	{
		o = o / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long int	i;
	long long int	j;
	char			*str;

	j = n;
	i = count(j);
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	if (j == -2147483648)
	{	
		return (ft_strcpy(str, "-2147483648"));
	}
	if (j < 0)
	{
		str[0] = '-';
		j = -j;
	}
	str[i - 1] = '\0';
	return (crea(j, str, i - 1));
}
