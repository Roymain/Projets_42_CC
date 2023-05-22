/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirection_second_part.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:37:19 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:01:36 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	first_j_cut(int j, t_list *list, char **cmd, t_mini *mini)
{
	if ((ft_strichr(cmd[j], '>') > -1 || ft_strichr(cmd[j], '<') > -1)
		&& !cmd[j + 1] && (!cmd[ft_strichr(cmd[j], '<') + 1]
			|| !cmd[ft_strichr(cmd[j], '>') + 1]))
		j++;
	else if (ft_strichr(cmd[j], '>') == -1
		&& ft_strichr(cmd[j], '<') == -1 && j == 0)
	{
		list->key = cmd[j];
		if (cmd[j + 1])
			j++;
	}
	else if ((ft_strichr(cmd[j], '>') > -1
			|| ft_strichr(cmd[j], '<') > -1) && j == 0)
	{
		if (!cmd[j][ft_strichr(cmd[j], '<') + 1]
			|| !cmd[j][ft_strichr(cmd[j], '>') + 1])
			j++;
		list->key = ft_track(ft_strdup(""), mini->track_cmd);
		j++;
	}
	return (j);
}

static int	second_j_cut(int j, char **cmd, t_list *list, t_mini *mini)
{
	if ((ft_strichr(cmd[j], '>') > -1
			|| ft_strichr(cmd[j], '<') > -1) && j == 0)
	{
		if ((!cmd[j][ft_strichr(cmd[j], '>') + 1]
			|| !cmd[j][ft_strichr(cmd[j], '<') + 1]) && cmd[j + 1])
			j++;
		else if (cmd[j][ft_strichr(cmd[j], '>') + 1] == '>' )
		{
			if (!cmd[j][ft_strichr(cmd[j], '>') + 2])
				j++;
		}
	}
	else if (ft_strichr(cmd[j], '-') == 0 && j != 0)
		list->key = ft_track(ft_strjoin(list->key, cmd[j] + \
			(ft_strichr(cmd[j], '-'))), mini->track_cmd);
	else if (j != 0 && ft_strichr(cmd[j], '>') == -1
		&& ft_strichr(cmd[j], '<') == -1)
		list->key = ft_track(ft_strjoin(list->key, cmd[j]), mini->track_cmd);
	return (j);
}

static int	third_j_cut(int j, char **cmd, t_list *list, t_mini *mini)
{
	if (ft_strichr(cmd[j], '-') == -1 && ft_strichr(cmd[j], '>') \
		== -1 && ft_strichr(cmd[j], '<') == -1 && j != 0 && !list->key[0])
		list->key = ft_track(ft_strjoin(list->key, cmd[j]), mini->track_cmd);
	else if (ft_strichr(cmd[j], '>') > -1)
	{
		if (!cmd[j][ft_strichr(cmd[j], '>') + 1] && cmd[j + 1])
			j++;
		else if (cmd[j][ft_strichr(cmd[j], '>') + 1] == '>')
		{
			if (!cmd[j][ft_strichr(cmd[j], '>') + 2])
				j++;
		}
	}
	else if (ft_strichr(cmd[j], '<') > -1)
	{
		if ((!cmd[j][ft_strichr(cmd[j], '<') + 1] && cmd[j + 1])
			|| cmd[j][ft_strichr(cmd[j], '<') + 1] == '<')
			j += 2;
	}
	return (j);
}

void	mini_do_loop(char **cmd, int j, t_mini *mini, t_list *list)
{
	while (cmd[j])
	{
		if (cmd[j])
			j = first_j_cut(j, list, cmd, mini);
		if (cmd[j])
			j = second_j_cut(j, cmd, list, mini);
		if (cmd[j])
			j = third_j_cut(j, cmd, list, mini);
		if (cmd[j])
			j++;
	}
}
