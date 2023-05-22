/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:51:09 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/09 15:06:39 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize)
{
	unsigned char		*tab;
	size_t				i;

	i = 0;
	tab = (void *)malloc(elementCount * elementSize);
	if (!tab)
		return (NULL);
	while (i < elementCount * elementSize)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
