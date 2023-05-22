/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:54:07 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/25 18:11:34 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*dest;
	size_t				i;
	unsigned int		j;

	if (!s)
		return (NULL);
	j = len;
	i = 0;
	if ((ft_strlen(s) - start) >= len)
		j = len;
	else
		j = ft_strlen(s) - start;
	if (j <= 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
