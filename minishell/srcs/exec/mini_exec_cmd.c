/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:11:36 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:19 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_exec.h"

static void	mini_no_back(char **str)
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

void	ft_execcmd(t_cmd *cmd, char **env, t_env *ennv, t_mini *mini)
{
	char	*path;
	char	**split;
	pid_t	pid;

	pid = 0;
	path = NULL;
	if (ft_isitbuiltin(cmd->listcmd->key) == 1)
		return (ft_execbuiltin(cmd->listcmd, pid, ennv, mini));
	mini_shell_level(cmd->listcmd->key, ennv);
	split = ft_split(cmd->listcmd->key, ' ', 0);
	ft_track_tab((void **)split, mini->track_cmd);
	mini_no_back(split);
	path = checkpath(env, split, cmd->listcmd->key, mini);
	if (ft_strncmp(cmd->listcmd->key, path, ft_strlen(cmd->listcmd->key)) == 0
		&& !(cmd->listcmd->key[0] == '/' || cmd->listcmd->key[0] == '.'))
		return (mini_not_found(cmd, ennv, path));
	pid = fork();
	if (pid == -1)
		return (perror("error fork"));
	if (pid)
		ft_scotch_sign(ennv, pid);
	else
		ft_scotchredir(cmd->listcmd, path, split, env);
}
