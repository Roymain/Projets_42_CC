/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:45:15 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/31 23:42:50 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(char *key, char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content[0] != '\0')
	{
		new->key = key;
		new->content = content;
		new->redir = NULL;
	}
	else
	{
		new->key = key;
		new->content = NULL;
		new->redir = NULL;
	}
	new->key = key;
	new->next = NULL;
	new->prev = NULL;
	new->redir = NULL;
	return (new);
}
