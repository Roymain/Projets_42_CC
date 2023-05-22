/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell_level.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:15:19 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:03:29 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_exec.h"
#include "../../../includes/mini_parsing.h"

static void	mini_is_minishell(const char *str, t_env *env, int shellv)
{
	char	*new_level;

	new_level = NULL;
	if (access(str, F_OK) == 0)
	{
		new_level = mini_add("SHLVL=", shellv);
		mini_export_modif(env->list, new_level);
	}
	free(new_level);
	new_level = NULL;
}

bool	mini_shell_level(const char *str, t_env *env)
{
	uint64_t	shellv;

	shellv = mini_atoi(mini_return("$SHLVL", env));
	if (ft_strncmp("./minishell", str, ft_strlen("./minishell")) == 0)
	{
		mini_is_minishell(str, env, shellv);
		return (true);
	}
	return (false);
}
