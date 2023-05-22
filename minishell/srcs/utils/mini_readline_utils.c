/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_readline_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:20:03 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:48:07 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	mini_handler(int num)
{
	(void)num;
	if (waitpid(-1, NULL, 0) != -1)
	{
		printf("\n");
		// rl_replace_line("", 0);
		// rl_redisplay();
	}
	else
	{
		printf("\n");
		// rl_on_new_line();
		// rl_replace_line("", 0);
		// rl_redisplay();
	}
}

void	mini_quit(int num)
{
	(void)num;
	if (waitpid(-1, NULL, 0) != -1)
	{
		printf("\n");
		// rl_replace_line("", 0);
		// rl_redisplay();
	}
	else
	{
		// rl_on_new_line();
		// rl_replace_line("", 0);
		// rl_redisplay();
	}
}
