/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:26:42 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 19:38:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_transfert(t_val val)
{
	int	i;

	i = 0;
	while (i < val.len)
	{
		val.input[i] = val.output[i];
		i++;
	}
	i = 0;
	while (i < 10)
	{
		val.trieur[i] = 0;
		i++;
	}	
}

int	*tabneg(t_val val, int *neg, int i, int j)
{
	while (i >= 0)
	{
		if (val.input[i] <= 0)
		{
			neg[j] = val.input[i];
			j++;
		}
		i--;
	}
	return (neg);
}

int	*tabpos(t_val val, int *pos, int i, int k)
{
	while (i <= val.len)
	{
		if (val.input[i] > 0)
		{
			pos[k] = val.input[i];
			k++;
		}	
		i++;
	}
	return (pos);
}

int	*tabinput(t_val val, int *pos, int *neg)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < val.nbrneg)
	{
		val.input[i] = neg[i];
		i++;
	}
	while (i < val.len && pos[k])
	{
		val.input[i] = pos[k];
		i++;
		k++;
	}
	return (val.input);
}

void	ft_cumulprefix(t_val *val, int coef)
{
	int	i;

	i = 0;
	while (i < val->len)
	{
		val->trieur[ft_prefix(val->input[i], coef)] += 1;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		val->trieur[i] += val->trieur[i - 1];
		i++;
	}
}
