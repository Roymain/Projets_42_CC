/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:22:17 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/11 22:31:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_c(char c, const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || s[i] == '\0')
			{
				j++;
			}
		}
		if (s[i])
			i++;
	}
	if (j == 0)
		return (2);
	return (j + 1);
}

static int	ft_check_c(char c, char s)
{
	if (c == s)
		return (1);
	return (0);
}

static char	*ft_strdupp(char const *s, char c, int *i)
{
	char	*str;
	int		size;
	int		j;

	str = 0;
	size = 0;
	j = 0;
	while (ft_check_c(s[*i], c) == 0 && s[*i])
	{
		size++;
		*i += 1;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (ft_calloc(1, 0));
	*i = *i - size;
	while (ft_check_c(s[*i], c) == 0 && s[*i])
	{
		str[j] = s[*i];
		*i += 1;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static int	freeall(char *str, char **dstr, int i)
{
	if (!str)
	{
		while (i >= 0)
		{
			free(dstr[i]);
			i--;
		}
		free(dstr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_c(c, s)));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (ft_check_c(c, s[i]) == 0)
		{
			str[j] = ft_strdupp(s, c, &i);
			if (j < ft_count_c(c, s) && freeall(str[j], str, j) == 1)
				return (NULL);
			j++;
		}
		else
			i++;
	}
	str[j] = 0;
	return (str);
}
