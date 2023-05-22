/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:07:00 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/19 21:40:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_replace(char *buffer, int i)
{
	int	j;

	j = 0;
	i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	while (j <= i)
	{
		buffer[j] = '\0';
		j++;
	}
	return (buffer);
}

int	ft_checkn(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != c)
		i++;
	return (i);
}

char	*ft_realloc(char *strr, int i, char *buffer)
{
	char	*temp;
	int		j;
	int		k;

	temp = NULL;
	k = 0;
	j = ft_strlen(strr);
	temp = ft_calloc (j + i + 2, 1);
	while (strr[k] != '\0')
	{
		temp[k] = strr[k];
		k++;
	}
	temp[k + i + 1] = '\0';
	while (i >= 0)
	{
		temp[k + i] = buffer[i];
		i--;
	}
	free (strr);
	strr = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || (!buffer[fd][0]
		&& read (fd, buffer[fd], BUFFER_SIZE) < 1))
	{
		if (line)
			free(line);
		return (NULL);
	}
	i = ft_checkn(buffer[fd], '\n');
	line = ft_calloc (i + 1, 1);
	while (i == ft_strlen(buffer[fd]))
	{
		line = ft_realloc(line, i, buffer[fd]);
		ft_replace(buffer[fd], i);
		if (read (fd, buffer[fd], BUFFER_SIZE) == 0)
			return (line);
		i = ft_checkn(buffer[fd], '\n');
	}
	line = ft_realloc(line, i, buffer[fd]);
	ft_replace(buffer[fd], i);
	return (line);
}
