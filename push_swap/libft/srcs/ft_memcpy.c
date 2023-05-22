/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:52:05 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 20:01:12 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;
	int				j;

	j = n;
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
		return (dest);
	while (i < j)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dest);
}
