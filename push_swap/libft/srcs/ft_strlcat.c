/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:53:39 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 20:01:37 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(dst);
	if (dstsize < count || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (src[i] != '\0' && i + count < dstsize - 1)
	{
		dst[i + count] = src[i];
		i++;
	}
	dst[i + count] = '\0';
	return (count + ft_strlen(src));
}
