/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:31:33 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 20:00:47 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
		lst = lst->next;
		ft_lstadd_back(&add, var);
	}
	return (add);
}
