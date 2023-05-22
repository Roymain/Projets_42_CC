/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:31:16 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/29 19:39:24 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*suite(t_list *tmp, t_val *val)
{
	if (*((int *)(val->pilea)->next->content) == val->max)
	{
		ft_rotatepilea(&val->pilea);
		ft_rotatepilea(&val->pilea);
	}
	else
		ft_callswap(&val->pilea, tmp);
	return (val->pilea);
}

t_list	*ft_castrois(t_list *tmp, t_val val)
{
	val = ft_minmax(val.pilea, tmp, val);
	if (*((int *)(val.pilea)->content) == val.max)
	{
		if (*((int *)(val.pilea)->next->content) == val.min)
			ft_rotatepilea(&val.pilea);
		else
		{
			ft_rotatepilea(&val.pilea);
			ft_callswap(&val.pilea, tmp);
		}
	}
	if (*((int *)(val.pilea)->content) == val.min)
	{
		if (*((int *)(val.pilea)->next->content) == val.max)
		{
			ft_callswap(&val.pilea, tmp);
			ft_rotatepilea(&val.pilea);
		}
	}
	else
	{
		val.pilea = suite(tmp, &val);
	}
	return (val.pilea);
}

t_list	*ft_cascinq(t_list *tmp, t_val *val)
{
	*val = ft_minmax(val->pilea, tmp, *val);
	if (*((int *)(ft_lstlast(val->pilea))->content) == val->min)
		ft_rotaterevpilea(&val->pilea);
	if (val->pilea->next && *((int *)(val->pilea)->next->content) == val->min)
		ft_callswap(&val->pilea, tmp);
	while (*((int *)(val->pilea)->content) != val->min)
		ft_rotatepilea(&val->pilea);
	ft_pushb(&val->pilea, &val->pileb);
	if (val->pilea)
	{
		*val = ft_minmax(val->pilea, tmp, *val);
		while (*((int *)(val->pilea)->content) != val->min)
			ft_rotatepilea(&val->pilea);
		ft_pushb(&val->pilea, &val->pileb);
		*val = ft_minmax(val->pilea, tmp, *val);
		val->pilea = ft_castrois(tmp, *val);
	}
	if (*((int *)(val->pileb)->content) < *((int *)(val->pileb)->next->content))
		ft_rotatepileb(&val->pileb);
	ft_pusha(&val->pilea, &val->pileb);
	ft_pusha(&val->pilea, &val->pileb);
	return (val->pilea);
}

t_list	*caslow(int argc, t_val val)
{
	t_list	*tmp;

	tmp = val.pilea;
	if (argc == 4 || ft_lstsize(val.pilea) == 3)
	{
		val.pilea = ft_castrois(tmp, val);
	}
	if (argc == 6 || ft_lstsize(val.pilea) == 5)
	{
		val.pilea = ft_cascinq(tmp, &val);
	}
	return (val.pilea);
}
