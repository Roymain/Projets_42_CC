/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_display_error_errors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:06:12 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:44:38 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_builtin.h"

void	mini_display_exit_error(int error, const char *str, t_env *env)
{
	if (error == REQUIERED_NUMERIC)
	{
		printf("exit\nminishell: exit: %s: numeric argument required\n", str);
		env->return_value = 255;
		exit (255);
	}
}
