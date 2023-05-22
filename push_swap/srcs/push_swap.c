/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:48:28 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/05 05:02:31 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_casplus(t_val *val, int i, int count, int saveindex)
{
	t_list	*tmp;

	i = val->binlen - 1;
	while (i + 1 > 0)
	{
		tmp = val->pilea;
		saveindex = ft_saveindex(tmp, i);
		count = ft_countunit(&val->pilea, i);
		while (count > 0)
		{
			if (val->pilea->binary[i] == 0)
			{
				ft_pushb(&val->pilea, &val->pileb);
				count--;
			}
			else
				ft_rotatepilea(&val->pilea);
		}
		while (val->pilea->index != saveindex)
			ft_rotatepilea(&val->pilea);
		while (val->pileb)
			ft_pusha(&val->pilea, &val->pileb);
		i--;
	}
}

static void	suitemain(t_val val)
{
	int	i;
	int	coeff;

	val.nbrneg = ft_countneg(val);
	i = 1;
	coeff = ft_sizevalue(val.min, val.max);
	while (i <= coeff)
	{
		ft_cumulprefix(&val, i);
		ft_sortoutput(&val, i);
		ft_transfert(val);
		i++;
	}
	if (ft_countneg(val) > 0)
		ft_casneg(val);
	ft_addindex(&val);
	ft_casplus(&val, 0, 0, 0);
	free (val.input);
	free (val.output);
	free (val.trieur);
	ft_lstclear(&val.pilea, &free);
}

static void	allocation(t_val *val)
{
	t_list	*tmp;

	tmp = val->pilea;
	val->min = ft_checkmin(&tmp);
	tmp = val->pilea;
	val->max = ft_checkmax(&tmp);
	tmp = val->pilea;
	val->len = ft_lstsize(val->pilea);
	val->trieur = (int *)ft_calloc(10, sizeof(int));
	val->input = (int *)ft_calloc(val->len, sizeof(int));
	val->output = (int *)ft_calloc(val->len, sizeof(int));
	val->input = ft_parsinput(tmp, val->input);
}

void	ft_free(t_val val)
{
	free (val.input);
	free (val.output);
	free (val.trieur);
	ft_lstclear(&val.pilea, &free);
	ft_lstclear(&val.pileb, &free);
}

int	main(int argc, char **argv)
{
	t_val	val;

	val.pilea = NULL;
	val.pileb = NULL;
	if (argc == 1)
		return (0);
	if (ft_parsargv(argv, &val.pilea, argc, 1) == 1)
		return (write(2, "Error\n", 6));
	if (!val.pilea)
		return (write(2, "Error\n", 6));
	if (ft_checkorder(&val.pilea) == 0)
		return (0);
	allocation(&val);
	if (ft_checkdoublonstab(&val) == 0)
		return (write(2, "Error\n", 6));
	if (ft_lstsize(val.pilea) == 3 || ft_lstsize(val.pilea) == 5)
	{
		val.pilea = caslow(argc, val);
		ft_free(val);
		return (0);
	}
	suitemain(val);
	return (0);
}
