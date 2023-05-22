/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:37:37 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/18 04:18:08 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *theString)
{
	int	i;

	i = 0;
	if (!theString)
		return (i);
	while (theString[i])
	{
		i++;
	}
	return (i);
}

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
