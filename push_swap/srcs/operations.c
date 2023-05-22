/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:14:03 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/29 20:01:26 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushb(t_list **pilea, t_list **pileb)
{
	t_list	*tmp;

	tmp = *pileb;
	*pileb = *pilea;
	*pilea = (*pilea)->next;
	if (tmp)
		(*pileb)->next = tmp;
	else
		(*pileb)->next = NULL;
	write (1, "pb\n", 3);
}

void	ft_pusha(t_list **pilea, t_list **pileb)
{
	t_list	*tmp;

	tmp = *pilea;
	*pilea = *pileb;
	*pileb = (*pileb)->next;
	if (tmp)
		(*pilea)->next = tmp;
	else
		(*pilea)->next = NULL;
	write (1, "pa\n", 3);
}

void	ft_rotatepilea(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
	write (1, "ra\n", 3);
	return ;
}

void	ft_rotatepileb(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
	write (1, "rb\n", 3);
	return ;
}

void	ft_rotaterevpileb(t_list **pile)
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
	write (1, "rrb\n", 4);
	return ;
}
