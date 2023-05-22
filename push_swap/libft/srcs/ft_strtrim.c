/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:54:02 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 20:01:53 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strlenn(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	ft_sets(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (ft_check(s[i], set) == 1)
		i++;
	return (i);
}

static int	ft_sete(char const *s, char const *set)
{
	int	j;
	int	i;

	i = 0;
	j = ft_strlenn(s) - 1;
	while (ft_check(s[j], set))
	{
		j--;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	i = ft_sets(s1, set);
	if (ft_strlenn(s1) == ft_sets(s1, set))
		return (ft_strdup(""));
	str = malloc (sizeof(char) * (ft_strlenn(s1) - ft_sets(s1, set)
				- ft_sete(s1, set) + 1));
	if (!str)
		return (ft_strdup(""));
	while (j < (ft_strlenn(s1) - ft_sets(s1, set) - ft_sete(s1, set)))
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str [j] = '\0';
	return (str);
}
