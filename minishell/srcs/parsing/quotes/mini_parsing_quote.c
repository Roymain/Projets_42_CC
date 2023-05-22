/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:30:46 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:00:48 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	mini_condition(char **str, int i, t_mini *mini)
{
	if (ft_strichr(*str, '<') > 1)
	{
		if ((*str[i - 1] == '<' && *str[i - 2] == '<')
			|| (*str[i - 2] == '<' && *str[i - 3]))
		{
			*str[i] = ' ';
			i++;
			while (*str[i] != '"')
			{
				if (*str[i] == ' ')
					*str[i] = '\\';
				i++;
			}
			*str[i] = ' ';
		}
	}
	else
		*str = ft_double(*str, mini, &i);
	return (i);
}

static char	*mini_init_quotes(int *j, int *i, char *q, t_mini *mini)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_track(malloc((500) * sizeof(char)), mini->track_cmd);
	*q = 'q';
	*i = 0;
	*j = 0;
	return (tmp);
}

static void	mini_display_quote(const int *start, const int *stop,
	char *tmp, const char *str)
{
	int	i;
	int	j;

	i = *stop;
	j = *start;
	while (j < i && str[j])
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = 0;
}

static bool	mini_do_condition_quotes(int *i, char **str, t_mini *mini, char *q)
{
	char	*tmp;

	tmp = *str;
	if (*q == '\'')
		*str = ft_track(ft_simple(tmp, i), mini->track_cmd);
	else if (*q == '"')
	{
		mini_condition(&tmp, *i, mini);
		*i -= 1;
		*str = tmp;
		if (!tmp[*i])
			return (true);
	}
	return (false);
}

char	*ft_quotes(char *str, t_mini *mini, int i, char q)
{
	char	*tmp;
	int		j;

	tmp = mini_init_quotes(&j, &i, &q, mini);
	while (str[i] && str[i + 1])
	{
		if (str[i] == '\'' || str[i] == '"' || str[i] == '$')
		{
			q = str[i];
			if (mini_do_condition_quotes(&i, &str, mini, &q) == true)
				return (str);
			else if (q == '$')
			{
				mini_display_quote(&j, &i, tmp, str);
				str = mini_join_arg(str, mini, &i, tmp);
				i--;
			}
		}
		q = 'q';
		if (str[i + 1])
			i++;
	}
	return (str);
}
