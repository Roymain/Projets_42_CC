/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:15:10 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/31 02:16:31 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *src, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((sizeof(char) * size) + 1);
	if (str == NULL)
		return (0);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
