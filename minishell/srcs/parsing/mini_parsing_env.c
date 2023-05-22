/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:01:02 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:46:13 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parsenv(t_list **list, char **ev, t_track **t)
{
	int		i;
	t_list	*tmp;
	char	*content;
	char	*key;

	i = 0;
	while (ev[i])
	{
		key = ft_track(ft_strndup(ev[i], ft_strichr(ev[i], '=')), *t);
		content = ft_track(ft_strnndup(ev[i], ft_strichr(ev[i], '\0'),
					ft_strichr(ev[i], '=') + 1), *t);
		tmp = ft_lstnew(key, content);
		ft_track(tmp, *t);
		ft_lstadd_back(list, tmp);
		i++;
	}
}
