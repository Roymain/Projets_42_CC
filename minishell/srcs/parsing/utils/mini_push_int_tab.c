/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_int_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:02:36 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:01:56 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	**mini_push_int_tab(int *a, int *b)
{
	int	**to_be_push;

	to_be_push = malloc(sizeof(int *) * 2 + 1);
	to_be_push[0] = a;
	to_be_push[1] = b;
	return (to_be_push);
}
