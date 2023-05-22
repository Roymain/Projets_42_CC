/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:50 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:59:22 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/tracker.h"

t_track	*ft_lstlasttracker(t_track *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_backtotrack(t_track **alst, t_track *news)
{
	t_track	*var;

	if (*alst)
	{
		var = ft_lstlasttracker(*alst);
		var->next = news;
	}
	else if (!*alst && news)
		*alst = news;
	else
		*alst = NULL;
}

t_track	*ft_lstnewtracker(void **content)
{
	t_track	*new;

	new = malloc(sizeof(t_track));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstdelonetracker(t_track *lst, void (*del)(void*))
{
	if (lst)
	{
		if (del)
		{
			if (lst)
			{
				if (lst->content)
					del(lst->content);
				lst->content = NULL;
				free(lst);
				lst = NULL;
			}
		}
	}
}

void	ft_lstcleartracker(t_track **lst, void (*del)(void *))
{
	t_track	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelonetracker(*lst, del);
		(*lst) = next;
	}
}
