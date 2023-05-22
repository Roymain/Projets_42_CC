/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:31:33 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/05 18:08:11 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*var;
	t_list	*add;

	add = NULL;
	while (lst)
	{
		var = ft_lstnew(f(lst->content));
		if (!var->content)
			del(var->content);
		ft_lstadd_back(&add, var);
		lst = lst->next;
	}
	return (add);
}
