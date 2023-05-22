/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opeswap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:29:01 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/29 19:37:00 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_callswap(t_list **pilea, t_list *tmp)
{
	tmp = *pilea;
	*pilea = (*pilea)->next;
	tmp->next = (*pilea)->next;
	ft_swaptopa(pilea, tmp);
	return (*pilea);
}

t_val	ft_minmax(t_list *pile, t_list *tmp, t_val val)
{
	tmp = pile;
	val.min = ft_checkmin(&tmp);
	tmp = pile;
	val.max = ft_checkmax(&tmp);
	return (val);
}

void	ft_swaptopa(t_list **alst, t_list *new)
{
	if (*alst)
		(*alst)->next = new;
	else if (!*alst && new)
		*alst = new;
	else
		*alst = NULL;
	write (1, "sa\n", 3);
}

void	ft_swaptopb(t_list **alst, t_list *new)
{
	if (*alst)
		(*alst)->next = new;
	else if (!*alst && new)
		*alst = new;
	else
		*alst = NULL;
	write (1, "sb\n", 3);
}

void	ft_rotaterevpilea(t_list **pile)
{
	t_list	*tmp;
	t_list	*var;

	tmp = ft_lstlast(*pile);
	ft_lstadd_front(pile, tmp);
	var = *pile;
	while (var->next != tmp)
	{
		var = var->next;
	}
	var->next = NULL;
	write (1, "rra\n", 4);
	return ;
}
