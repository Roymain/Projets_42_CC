/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:20:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/31 04:45:22 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = lst;
	if (lst->next && lst->prev)
		lst->prev->next = lst->next;
	if (lst->next && !lst->prev)
		lst = lst->next;
	if (!lst->next && lst->prev)
		lst->prev->next = NULL;
	if (del)
	{
		del(tmp->content);
		del(tmp->key);
	}
	free(tmp);
}
