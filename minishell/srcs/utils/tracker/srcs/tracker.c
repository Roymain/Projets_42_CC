/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:31 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:59:40 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tracker.h"

void	ft_bzerotracker(void *s, size_t n)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}

void	*ft_memallocc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem)
	{
		ft_bzerotracker(mem, size);
		return (mem);
	}
	else
		return (NULL);
}

void	*ft_track_tab(void **tab, t_track *list)
{
	int	i;

	i = 0;
	if (tab)
		ft_lstadd_backtotrack(&list, ft_lstnewtracker(tab));
	while (tab[i])
	{
		if (tab[i])
			ft_lstadd_backtotrack(&list, ft_lstnewtracker(tab[i]));
		i++;
	}
	return ((void *)tab);
}

void	*ft_track(void *address, t_track *list)
{
	if (address)
		ft_lstadd_backtotrack(&list, ft_lstnewtracker(address));
	return (address);
}

int	ft_free_all(t_track *tracker)
{
	ft_lstcleartracker(&tracker, &(free));
	return (0);
}
