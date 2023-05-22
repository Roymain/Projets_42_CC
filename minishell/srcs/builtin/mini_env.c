/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:34 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:43:53 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_builtin.h"

void	builtin_env(t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (env->list)
	{
		if (env->list->content)
		{
			printf("%s=", env->list->key);
			printf("%s", env->list->content);
			printf("\n");
		}
		env->list = env->list->next;
	}
	env->list = tmp;
	env->return_value = 0;
}
