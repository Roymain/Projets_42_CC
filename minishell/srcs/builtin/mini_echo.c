/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:41:35 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:43:45 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_builtin.h"

static int	ft_optionecho(char *str)
{
	int	i;
	int	alpha;

	i = 0;
	alpha = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'n'
			&& str[i + 2] == ' ' && alpha == 0)
			return (1);
		if (ft_isprint(str[i]) == 1 && str[i] != ' ')
			alpha++;
		i++;
	}
	return (0);
}

static bool	mini_is_dolard(char *str)
{
	if (str[ft_strichr(str, '$') + 1] == '?'
		&& (!str[ft_strichr(str, '$') + 2]
			|| str[ft_strichr(str, '$') + 2] == ' '))
		return (true);
	return (false);
}

void	builtin_echo(char *str, t_env *env)
{
	int	option;

	option = ft_optionecho(str + 4);
	if (option == 0)
	{
		if (ft_strichr(str, '$') > -1 && mini_is_dolard(str) == true)
			printf("%d\n", env->return_value);
		else
			printf("%s\n", str + 5);
	}
	else
	{
		if (ft_strichr(str, '$') > -1 && mini_is_dolard(str) == true)
			printf("%d", env->return_value);
		else
			printf("%s", str + ft_strichr(str, '-') + 3);
	}
	env->return_value = 0;
}
