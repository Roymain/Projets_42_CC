/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:42 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:17 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*mini_no_back(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			str[i] = ' ';
		i++;
	}
	return (str);
}

void	ft_execbuiltin(t_list *cmd, pid_t pid, t_env *env, t_mini *mini)
{
	pid++;
	mini_no_back(cmd->key);
	if (cmd->key[0] != '\0')
	{
		if (cmd->redir)
			ft_redir(cmd->redir, cmd);
		ft_usebuiltin(cmd->key, env, mini);
	}
	dup2(cmd->fdout, 1);
}

void	ft_execbuiltinpipe(t_list *cmd, int	*pfd, t_env *ennv, t_mini *mini)
{
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		if (cmd->key[0] != '\0')
		{
			mini_no_back(cmd->key);
			if (cmd->redir)
				ft_redir(cmd->redir, cmd);
			ft_usebuiltin(cmd->key, ennv, mini);
			exit (1);
		}
	}
}

void	ft_execbuiltinn(t_list *cmd, int	*pfd, t_cmd *s, t_mini *mini)
{
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
		dup2(s->fdin, 0);
	else
	{
		if (cmd->key[0] != '\0')
		{
			mini_no_back(cmd->key);
			dup2(s->fdout, 1);
			if (cmd->redir)
				ft_redir(cmd->redir, cmd);
			ft_usebuiltin(cmd->key, mini->env, mini);
			exit (1);
		}
	}
}
