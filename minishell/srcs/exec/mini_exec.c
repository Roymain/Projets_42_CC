/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:30:21 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:27 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_exec.h"

static void	ft_unlink(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst);
	while ((*lst))
	{
		while ((*lst)->redir)
		{
			tmp2 = (*lst)->redir;
			if (ft_strncmp((*lst)->redir->key, "<< ", 2) == 0)
				unlink((*lst)->redir->content);
			(*lst)->redir = (*lst)->redir->next;
		}
		(*lst)->redir = tmp2;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}

static void	mini_no_back_possible(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\\')
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void	mini_cmd(t_cmd *cmd, char **env, int *pfd, t_mini *mini)
{
	char	*path;
	char	**split;
	pid_t	pid;

	path = NULL;
	if (ft_isitbuiltin(cmd->listcmd->key) == 1)
		return (ft_execbuiltinn(cmd->listcmd, pfd, cmd, mini));
	split = ft_split(cmd->listcmd->key, ' ', 0);
	ft_track_tab((void **)split, mini->track_cmd);
	mini_no_back_possible(split);
	path = checkpath(env, split, cmd->listcmd->key, mini);
	if (ft_strncmp(cmd->listcmd->key, path, ft_strlen(path)) == 0
		&& !(cmd->listcmd->key[0] == '/' || cmd->listcmd->key[0] == '.'))
		return (mini_not_found(cmd, mini->env, path));
	pipe(pfd);
	pid = fork();
	if (pid == -1)
		return (perror("error fork"));
	if (pid && dup2(pfd[0], 0) != -1)
		ft_scotch_sign_with_pfd(mini->env, pid, pfd);
	else
	{
		if (cmd->listcmd->key[0] != '\0' && dup2(cmd->fdout, 1) != -1)
			ft_scotchredir(cmd->listcmd, path, split, env);
	}
}

static void	mini_condition(t_mini *mini, char **ev, int *pfd)
{
	if (ft_checkifredir(&mini->cmd->listcmd) != 0)
		mini_pre_heredoc(&mini->cmd->listcmd);
	if (mini->cmd->listcmd != NULL && !mini->cmd->listcmd->next)
		ft_execcmd(mini->cmd, ev, mini->env, mini);
	if (mini->cmd->listcmd != NULL && mini->cmd->listcmd->next)
	{
		while (mini->cmd->listcmd->next)
		{
			ft_execcmdpipe(mini->cmd->listcmd, ev, pfd, mini);
			mini->cmd->listcmd = mini->cmd->listcmd->next;
		}
		mini_cmd(mini->cmd, ev, pfd, mini);
	}
}

void	ft_exec(t_mini *mini, t_list *tmp)
{
	char	**ev;
	int		pfd[2];

	ev = ft_trad(mini->env);
	tmp = mini->cmd->listcmd;
	mini_condition(mini, ev, pfd);
	dup2(mini->cmd->fdout, 1);
	dup2(mini->cmd->fdin, 0);
	while (waitpid(-1, NULL, 0) != -1)
		;
	mini->cmd->listcmd = tmp;
	if (ft_checkifredir(&mini->cmd->listcmd) != 0)
		ft_unlink(&mini->cmd->listcmd);
	ft_freetab(ev);
}
