/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:15:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/11 21:20:37 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strichr(const char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)to_find)
			return (i);
		i++;
	}
	if (str[i] == (char)to_find)
		return (i);
	return (-1);
}
