/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:45:39 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:01:48 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	mini_init_redir(
	t_list **tmp,
	t_list **tmp2,
	t_list *list,
	t_mini *mini)
{
	*tmp = mini->cmd->listcmd;
	*tmp2 = list;
	return (0);
}

static void	mini_loop_redir(int *i, char **cmd, t_mini *mini, int *j)
{
	while (cmd && cmd[*i])
	{
		*i = mini_redirection_first_part(cmd, mini, *i);
		if (!cmd[*i + 1] && *i != 0)
			return ;
		*i += 1;
		mini_do_loop(cmd, *j, mini, mini->cmd->listcmd);
		if (mini->cmd->listcmd->key[0] == '<' && !mini->cmd->listcmd->key[1])
			mini->cmd->listcmd->key[0] = '\0';
	}
}

void	ft_parse_redir(t_list *list, t_mini *mini)
{
	int		i;
	int		j;
	char	**cmd;
	t_list	*tmp;
	t_list	*tmp2;

	j = 0;
	i = mini_init_redir(&tmp, &tmp2, list, mini);
	while (mini->cmd->listcmd)
	{
		cmd = ft_split(mini->cmd->listcmd->key, ' ', 0);
		ft_track_tab((void *)cmd, mini->track_cmd);
		if (!cmd[i])
			mini->cmd->listcmd->key[0] = 0;
		mini_loop_redir(&i, cmd, mini, &j);
		mini->cmd->listcmd = mini->cmd->listcmd->next;
		j = 0;
		i = 0;
	}
	mini->cmd->listcmd = tmp;
}
