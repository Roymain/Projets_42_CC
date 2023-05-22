/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirection_first_part.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:37:38 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:01:10 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	mini_cut_condition(char **cmd, int *i, t_list *tmp, t_mini *mini)
{
	if (cmd[*i][(ft_strichr(cmd[*i], '<') + 1)])
	{
		tmp = ft_lstnew("<", cmd[*i] + (ft_strichr(cmd[*i], '<') + 1));
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
	}
	else if (cmd[*i + 1])
	{
		tmp = ft_lstnew("<", cmd[*i + 1]);
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		*i += 1;
	}
	else
		mini_display_redir_error();
}

static void	first_cut(char **cmd, int *i, t_list *tmp, t_mini *mini)
{
	if (cmd[*i][ft_strichr(cmd[*i], '<') + 1] == '<')
	{
		if (!cmd[*i][ft_strichr(cmd[*i], '<') + 2] && cmd[*i + 1])
		{
			tmp = ft_lstnew("<<", ft_track(ft_strdup(cmd[*i + 1]), \
					mini->track_cmd));
			ft_track(tmp, mini->track_cmd);
			ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
			*i += 1;
		}
		else if (cmd[*i][ft_strichr(cmd[*i], '<') + 2])
		{
			tmp = ft_lstnew("<<", ft_track(ft_strnndup(cmd[*i], \
					ft_strlen(cmd[*i]) - (ft_strichr(cmd[*i], '<') - 2), \
					ft_strichr(cmd[*i], '<') + 2), mini->track_cmd));
			ft_track(tmp, mini->track_cmd);
			ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		}
		else
			mini_display_redir_error();
	}
	else
		mini_cut_condition(cmd, i, tmp, mini);
}

static int	second_cut(char **cmd, int i, t_mini *mini, t_list *tmp)
{
	if (!cmd[i][ft_strichr(cmd[i], '>') + 2])
	{
		tmp = ft_lstnew(ft_track(ft_strndup(cmd[i], \
			(ft_strichr(cmd[i], '>') + 2)), mini->track_cmd), cmd[i + 1]);
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		i++;
	}
	else
	{
		tmp = ft_lstnew(ft_track(ft_strndup(cmd[i], \
			(ft_strichr(cmd[i], '>') + 2)), mini->track_cmd), ft_track(\
			ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (\
			ft_strichr(cmd[i], '>') - 2), ft_strichr(cmd[i], '>') + 2), \
			mini->track_cmd));
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
	}
	return (i);
}

static int	third_cut(char **cmd, int i, t_mini *mini, t_list *tmp)
{
	char	*help;

	if (!cmd[i][ft_strichr(cmd[i], '>') + 1] && cmd[i + 1])
	{
		help = ft_strndup(cmd[i], ft_strichr(cmd[i], '>') + 1);
		ft_track(help, mini->track_cmd);
		if (cmd[i + 1])
		{
			tmp = ft_lstnew(help, cmd[i + 1]);
			ft_track(tmp, mini->track_cmd);
			ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		}
		i++;
	}
	else if (cmd[i][ft_strichr(cmd[i], '>') + 1])
	{
		help = ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 1));
		ft_track(help, mini->track_cmd);
		tmp = ft_lstnew(help, cmd[i] + (ft_strichr(cmd[i], '>') + 1));
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
	}
	else
		mini_display_redir_error();
	return (i);
}

int	mini_redirection_first_part(char **cmd, t_mini *mini, int i)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_strichr(cmd[i], '<') > -1)
		first_cut(cmd, &i, tmp, mini);
	else if (ft_strichr(cmd[i], '>') > -1)
	{
		if (cmd[i][ft_strichr(cmd[i], '>') + 1] == '>')
			i = second_cut(cmd, i, mini, tmp);
		else
			i = third_cut(cmd, i, mini, tmp);
	}
	return (i);
}
