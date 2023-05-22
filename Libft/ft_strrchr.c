/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:54:00 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/09 08:54:00 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)to_find)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
