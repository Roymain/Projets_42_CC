/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_not_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:32:23 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:47 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_exec.h"

void	mini_not_found(t_cmd *cmd, t_env *env, char *path)
{
	dup2(cmd->fdout, 1);
	dup2(cmd->fdin, 0);
	env->return_value = 127;
	dprintf(2, "minishell: %s: command not found\n", path);
}
