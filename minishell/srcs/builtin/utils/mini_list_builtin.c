/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:21:05 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:44:44 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_builtin.h"

t_list	*ft_lstmapp(t_list *lst)
{
	t_list	*var;
	t_list	*add;

	add = NULL;
	while (lst)
	{
		var = ft_lstnew("", "");
		if (lst->content)
			var->content = ft_strdup(lst->content);
		var->key = ft_strdup(lst->key);
		lst = lst->next;
		ft_lstadd_back(&add, var);
	}
	return (add);
}

void	ft_lstsortswap(void *save, void *savee, t_list *current)
{
	save = NULL;
	savee = NULL;
	save = current->content;
	savee = current->key;
	current->content = current->next->content;
	current->key = current->next->key;
	current->next->content = save;
	current->next->key = savee;
}

t_list	*ft_lstsort(t_list *begin_list, int i, int j, int size)
{
	t_list	*help;
	t_list	*current;
	void	*save;
	void	*savee;

	save = NULL;
	savee = NULL;
	size = ft_lstsize(begin_list);
	help = ft_lstmapp(begin_list);
	while (i < size)
	{
		j = 0;
		current = help;
		while (j < size - 1 - i)
		{
			if (current->key[0] > current->next->key[0])
				ft_lstsortswap(save, savee, current);
			current = current->next;
			j++;
		}
		i++;
	}
	return (current);
}

int	print_list(t_list *list)
{
	while (list)
	{
		printf("declare -x ");
		printf("%s=\"", list->key);
		if (!list->content || list->content[0] == ' ')
			printf("\"\n");
		else
			printf("%s\"\n", list->content);
		list = list->next;
	}
	return (1);
}
