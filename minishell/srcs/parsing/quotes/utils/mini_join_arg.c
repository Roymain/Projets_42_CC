/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_join_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:44:55 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:00:56 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	mini_condition_arg(char **tmp, t_mini *mini, char *arg)
{
	if (ft_strncmp(arg, "$?", 2) == 0)
		*tmp = ft_track(mini_strjoin(*tmp,
					ft_track(ft_itoa(mini->env->return_value), \
					mini->track_cmd)), mini->track_cmd);
	else
		*tmp = ft_track(mini_strjoin(*tmp,
					mini_return(arg, mini->env)), mini->track_cmd);
}

char	*mini_join_arg(char *str, t_mini *mini, int *stri, char *tmp)
{
	char	*arg;
	int		j;

	arg = ft_track(malloc(208 * sizeof(char)), mini->track_cmd);
	j = 1;
	arg[j - 1] = '$';
	*stri += 1;
	while (str[*stri] && ft_isalnum(str[*stri]) == 1)
	{
		arg[j] = str[*stri];
		j++;
		*stri += 1;
	}
	if (j == 1 && str[*stri] == '?')
	{
		arg[j++] = '?';
		*stri += 1;
	}
	arg[j] = 0;
	mini_condition_arg(&tmp, mini, arg);
	j = ft_strlen(tmp) - 1;
	if (str[*stri])
		tmp = ft_track(mini_strjoin(tmp, str + *stri), mini->track_cmd);
	*stri = j;
	return (tmp);
}
