/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:57:43 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:02:01 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*mini_return(char *arg, t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, arg + 1, ft_strlen(arg)) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return ("");
}
