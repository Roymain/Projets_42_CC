/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:34:34 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 23:12:06 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countneg(t_val val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < val.len)
	{
		if (val.input[j] <= 0)
			i++;
		j++;
	}
	return (i);
}

void	ft_casneg(t_val val)
{
	int	*negative;
	int	*positive;
	int	i;
	int	j;
	int	k;

	i = val.len - 1 ;
	j = 0;
	k = 0;
	negative = malloc(sizeof(int) * ft_countneg(val));
	if (!negative)
		return ;
	positive = malloc(sizeof(int) * val.len - ft_countneg(val));
	if (!positive)
		return ;
	negative = tabneg(val, negative, i, j);
	positive = tabpos(val, positive, 0, k);
	val.input = tabinput(val, positive, negative);
	free (negative);
	free (positive);
}

int	*ft_dec_to_bin(int nbr, int size)
{
	int	*binary;

	binary = (int *)malloc(sizeof(int) * size);
	if (!binary)
		return (NULL);
	while (nbr > 0)
	{
		size--;
		binary[size] = nbr % 2;
		nbr /= 2;
	}
	while (size > 0)
	{
		size--;
		binary[size] = 0;
	}
	return (binary);
}

void	ft_addindex(t_val *val)
{
	int		i;
	t_list	*pile;

	pile = val->pilea;
	val->binlen = ft_count_len_binary(val->len - 1);
	while (pile->next)
	{
		i = 0;
		while (val->input[i] != *((int *)(pile)->content))
			i++;
		pile->index = i;
		pile->binary = ft_dec_to_bin(i, val->binlen);
		pile = pile->next;
	}
	i = 0;
	while (val->input[i] != *((int *)(pile)->content))
		i++;
	pile->index = i;
	pile->binary = ft_dec_to_bin(i, val->binlen);
}
