/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:20:32 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 19:11:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list **pa, t_val *env)
{
	t_list	*tmp;
	int		i;

	tmp = *pa;
	printf("\n");
	while (tmp->next)
	{
		i = 0;
		printf("[");
		while (i < env->binlen)
		{
			printf("%d", tmp->binary[i]);
			i++;
		}
		printf("]  [%d] ====> [%d]   \n", tmp->index, *((int *)(tmp)->content));
		tmp = tmp->next;
	}
	i = 0;
	printf("[");
	while (i < env->binlen)
	{
		printf("%d", tmp->binary[i]);
		i++;
	}
	printf("]  [%d] ====> [%d] \n", tmp->index, *((int *)(tmp)->content));
}

void	ft_print(t_val val)
{
	int	i;

	i = 0;
	printf("output     \n");
	while (i < val.len)
	{
		printf("[%d] = %d \n", i, val.input[i]);
		i++;
	}
	printf("\n");
}

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		dprintf(1, "%d   ", lst->index);
		dprintf(1, "%d\n", *((int *)(lst)->content));
		lst = lst->next;
	}
	dprintf(1, "\n");
	return ;
}
