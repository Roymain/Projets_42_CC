/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:27:36 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/11 15:03:48 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "gnl/get_next_line.h"

int	*ft_parsing(int *tab, int fd, int *maxx)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	tab = NULL;
	str = NULL;
	str = get_next_line(fd);
	tab = malloc(sizeof(int) * ft_strlen(str));
	while (str && str[i] && str[i + 1] != '\0')
	{
		tab[j] = ft_atoi(str, &i);
		ft_atoi_color(str, &i);
		j++;
		i++;
	}
	free(str);
		*maxx = j;
	return (tab);
}

// int	*ft_parsing_color(int *color, int fd)
// {
// 	char	*str;
// 	int		j;
// 	int		i;

// 	j = 0;
// 	i = 0;
// 	str = NULL;
// 	color = NULL;
// 	str = get_next_line(fd);
// 	color = malloc(sizeof(int) * ft_strlen(str));
// 	while (str && str[i])
// 	{
// 		color[j] = ft_atoi_color(str, &i);
// 		j++;
// 		i++;
// 	}
// 	return (color);
// }

int	ft_countline(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = get_next_line(fd);
	if (str)
		i++;
	while (str)
	{
		free (str);
		str = get_next_line(fd);
		if (str)
			i++;
	}
	free (str);
	close (fd);
	return (i);
}

static int	ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_color(char *str, int *i)
{
	int	result;

	result = 0;
	if (str[*i] == ',')
		*i += 1;
	if (str[*i] == '0')
		*i += 1;
	if (str[*i] == 'x')
		*i += 1;
	while ((str[*i] >= '0' && str[*i] <= '9')
		|| (str[*i] >= 'A' && str[*i] <= 'Z')
		|| (str[*i] >= 'a' && str[*i] <= 'z'))
	{
		result = result * 16 + ft_isdigit_base(str[*i], 16);
		*i += 1;
	}
	if (result == 0)
		return (0xFFFFFF);
	return (result);
}
