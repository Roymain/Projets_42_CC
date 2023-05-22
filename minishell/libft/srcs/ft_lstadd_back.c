/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:56:50 by rcuminal          #+#    #+#             */
/*   Updated: 2022/02/18 23:26:48 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*var;

	if (*alst)
	{
		var = ft_lstlast(*alst);
		var->next = new;
		new->prev = var;
		new->next = NULL;
	}
	else if (!*alst && new)
		*alst = new;
	else
		*alst = NULL;
}
