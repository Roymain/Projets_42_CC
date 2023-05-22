/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:08:31 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:22 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_closepfd(int *pfd)
{
	close(pfd[1]);
	close(pfd[0]);
}

static void	cut_cmdpipe(int *pfd, char *path)
{
	dup2(pfd[0], 0);
	dprintf(2, "minishell: %s: command not found\n", path);
}

static void	ft_nobackpossible(char **str)
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

void	ft_execcmdpipe(t_list *cmd, char **ev, int	*pfd, t_mini *mini)
{
	char	*path;
	char	**split;
	pid_t	p;

	path = NULL;
	if (ft_isitbuiltin(cmd->key) == 1)
		return (ft_execbuiltinpipe(cmd, pfd, mini->env, mini));
	split = ft_track_tab((void **)ft_split(cmd->key, ' ', 0), mini->track_cmd);
	ft_nobackpossible(split);
	path = checkpath(ev, split, cmd->key, mini);
	pipe(pfd);
	if (ft_strncmp(cmd->key, path, ft_strlen(path)) == 0
		&& !(cmd->key[0] == '/' || cmd->key[0] == '.'))
		return (cut_cmdpipe(pfd, path));
	p = fork();
	if (p == -1)
		return (perror("error fork"));
	if (p && dup2(pfd[0], 0) != -1)
		ft_closepfd(pfd);
	else
	{
		dup2(pfd[1], 1);
		ft_closepfd(pfd);
		ft_scotchredir(cmd, path, split, ev);
	}
}
