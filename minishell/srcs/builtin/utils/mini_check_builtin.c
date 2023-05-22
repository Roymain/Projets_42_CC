/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_check_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:55:00 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:44:34 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_builtin.h"

static void	mini_init_list(char *list[10])
{
	list[0] = "exit ";
	list[1] = "unset ";
	list[2] = "export ";
	list[3] = "export";
	list[4] = "cd ";
	list[5] = "cd";
	list[6] = "pwd";
	list[7] = "env";
	list[8] = "echo ";
	list[9] = NULL;
}

bool	ft_isitbuiltin(const char *str)
{
	char	*built_list[10];
	size_t	i;

	mini_init_list(built_list);
	i = 0;
	while (built_list[i])
	{
		if (ft_strncmp(str, built_list[i], ft_strlen(built_list[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}
