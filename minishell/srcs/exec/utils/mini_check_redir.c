/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_check_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:01:04 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:38 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_exec.h"

int	ft_checkifredir(t_list **lst)
{
	t_list		*tmp;
	t_list		*tmp2;
	int			i;

	i = 0;
	tmp = (*lst);
	while ((*lst))
	{
		if ((*lst)->redir != NULL)
		{
			tmp2 = (*lst)->redir;
			while ((*lst)->redir)
			{
				if (ft_strncmp((*lst)->redir->key, "<< ", 2) == 0)
					i++;
				(*lst)->redir = (*lst)->redir->next;
			}
			(*lst)->redir = tmp2;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
	return (i);
}
