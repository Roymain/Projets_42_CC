/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:01:52 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/29 19:17:58 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countunit(t_list **temp, int unit)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *temp;
	while (tmp)
	{
		if (tmp->binary[unit] == 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_checkmin(t_list **pile)
{
	int	i;

	i = 2147483647;
	while (*pile)
	{
		if (*(int *)(*pile)->content < i)
			i = *(int *)(*pile)->content;
		*pile = (*pile)->next;
	}
	return (i);
}

int	ft_checkmax(t_list **pile)
{
	int	i;

	i = -2147483648;
	while (*pile)
	{
		if (*(int *)(*pile)->content > i)
			i = *(int *)(*pile)->content;
		*pile = (*pile)->next;
	}
	return (i);
}

int	ft_checkorder(t_list **pile)
{
	t_list	*tmp;
	int		i;

	tmp = *pile;
	i = 0;
	while (tmp->next)
	{
		i = *(int *)tmp->content;
		if (*(int *)tmp->next->content > i)
			tmp = tmp->next;
		else
			return (1);
	}
	if (*(int *)tmp->content < i)
		return (1);
	ft_lstclear(pile, &free);
	return (0);
}

int	ft_checkdoublonstab(t_val *val)
{
	int	i;
	int	j;

	i = 0;
	while (i < val->len)
	{
		j = 0;
		while (j < val->len)
		{
			if (val->input[i] == val->input[j] && j != i)
			{
				ft_free(*val);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
