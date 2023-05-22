/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_double_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:39:41 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:00:47 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	mini_arg_loop(char *str, int *index[2], char *arg)
{
	int	j;

	j = 0;
	while (str[*index[1]] && str[*index[1]] != ' '
		&& str[*index[1]] != '"' && str[*index[1]] != '\''
		&& (j == 0 || ft_isalnum(str[*index[1]]) == 1))
	{
		arg[j] = str[*index[1]];
		j++;
		*index[0] += 1;
		*index[1] += 1;
	}
	arg[j] = 0;
	return (j);
}

static char	*mini_arg_join(char *str, t_mini *mini, char *tmp, int *index[2])
{
	char	*arg;
	char	*tmp2;

	arg = malloc(10000 * sizeof(char));
	*index[0] += 1;
	mini_arg_loop(str, index, arg);
	tmp2 = tmp;
	tmp = mini_strjoin(tmp2, mini_return(arg, mini->env));
	*index[0] = ft_strlen(tmp) - 1;
	if (str[*index[1] + 1])
	{
		free(tmp2);
		tmp2 = tmp;
		tmp = mini_strjoin(tmp2, str + *index[1] + 1);
	}
	*index[1] -= 1;
	free(index);
	free(arg);
	free(tmp2);
	return (tmp);
}

static int	mini_skip(const char *str, int *max_value, char *tmp)
{
	int	j;

	j = 0;
	while (str[j] && j < *max_value)
	{
		tmp[j] = str[j];
		j++;
	}
	*max_value += 1;
	return (j);
}

static char	*mini_in_double_quote(char *str, int *i, t_mini *mini)
{
	char	*tmp;
	int		j;

	tmp = malloc((ft_strlen(str) + 1) * \
		sizeof(char));
	j = mini_skip(str, i, tmp);
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$' && ft_isalnum(str[*i + 1]) == 1)
		{
			tmp[j] = 0;
			tmp = mini_arg_join(str, mini, tmp, mini_push_int_tab(&j, i));
		}
		else
		{
			if (str[*i] == ' ')
				tmp[j] = '\\';
			else
				tmp[j] = str[*i];
		}
		j++;
		*i += 1;
	}
	tmp[j] = 0;
	return (tmp);
}

char	*ft_double(char *str, t_mini *mini, int *i)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp = mini_in_double_quote(str, i, mini);
	if (str[*i] && str[*i + 1])
	{
		tmp2 = tmp;
		tmp = mini_strjoin(tmp2, str + *i + 1);
		free (tmp2);
	}
	*i -= 1;
	ft_track(tmp, mini->track_cmd);
	return (tmp);
}
