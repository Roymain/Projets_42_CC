/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_modify_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:40:17 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:03:03 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/mini_exec.h"

static int	ft_strenvcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] != '=')
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (s1[i] == '=' && !s2[i])
		return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	mini_export_modif(t_list *list, const char *content)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strenvcmp(content, tmp->key) == 0)
		{
			if (tmp->content && ft_strichr(content, '=') > 0)
			{
				tmp->content = ft_strnndup(content, ft_strichr(content, '\0'),
						ft_strichr(content, '=') + 1);
			}
			else
				tmp->content = NULL;
		}
		tmp = tmp->next;
	}
}
