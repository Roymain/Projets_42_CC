/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:25:39 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:46:11 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_nextchar(char *str, int *retrn)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|' || (i == 0 && !str[i]) || !str[i])
	{
		*retrn = 1;
		return (1);
	}
	else
		return (0);
}

static char	mini_in_quote(const char *line, int i, char quote)
{
	if (line[i + 1] != '\0' && (line[i] == '"'
			|| line[i] == '\''))
		quote = line[i];
	else if (line[i + 1] != '\0' && line[i] == quote)
		quote = 0;
	return (quote);
}

static void	mini_init_parsing_line(int *i, int *start, char *quote, int *retrn)
{
	*i = -1;
	*start = 0;
	*quote = 0;
	*retrn = 0;
}

static void	mini_norme(char *line, int *i, int *start, t_mini *mini)
{
	t_list	*tmp;

	if (line[*i + 1] == '\0')
		*i += 1;
	tmp = ft_lstnew(ft_track(ft_strndup(line + *start, (*i - *start)),
				mini->track_cmd), "");
	tmp->key = ft_quotes(tmp->key, mini, 0, 'q');
	ft_track(tmp, mini->track_cmd);
	ft_lstadd_back(&(mini->cmd->listcmd), tmp);
	*start = *i + 1;
}

int	mini_parsing_line(char *line, t_mini *mini)
{
	int		i;
	int		start;
	char	quote;
	int		retrn;

	mini_init_parsing_line(&i, &start, &quote, &retrn);
	while (line[++i] != '\0')
	{
		quote = mini_in_quote(line, i, quote);
		if ((!quote && line[i] == '|' \
			&& ft_nextchar(line + i + 1, &retrn) == 0) || line[i + 1] == '\0')
		{
			mini_norme(line, &i, &start, mini);
			if (line[i] == '\0')
				break ;
		}
	}
	ft_parse_redir(mini->cmd->listcmd, mini);
	return (retrn);
}
