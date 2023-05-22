/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsindex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:22:10 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/29 19:42:39 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_saveindex(t_list *tmp, int unit)
{
	while (tmp->binary[unit] != 1)
		tmp = tmp->next;
	return (tmp->index);
}

void	ft_rotatenonoffi(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
	return ;
}

int	ft_sizevalue(int min, int max)
{
	int	i;

	i = 0;
	if (min < 0)
		min = -min;
	if (max < 0)
		max = -max;
	if (min > max)
		max = min;
	while (max > 0)
	{
		max = max / 10;
		i++;
	}
	return (i);
}

int	ft_prefix(int tab, int coeff)
{
	if (tab == -2147483648 && coeff > 1)
		tab = 2147483647;
	if (tab == -2147483648 && coeff == 1)
		return (8);
	if (tab < 0)
		tab = -tab;
	while (coeff - 1 > 0)
	{
		tab /= 10;
		coeff--;
	}
	tab = tab % 10;
	return (tab);
}

int	ft_count_len_binary(int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 2;
		i++;
	}
	return (i);
}
