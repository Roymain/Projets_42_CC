/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:53:27 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 20:01:26 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)to_find)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)to_find)
		return ((char *)&str[i]);
	return (NULL);
}
