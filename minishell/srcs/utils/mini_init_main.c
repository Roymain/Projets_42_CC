/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:15:52 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:46:30 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	mini_init(t_mini *mini, int argc, char **argv)
{
	t_env	env;
	t_cmd	cmd;
	t_track	trackenv;
	t_track	trackcmd;

	(void)argc;
	(void)argv;
	mini->cmd = &cmd;
	mini->track_cmd = &trackcmd;
	mini->env = &env;
	mini->env = 0;
	mini->track_env = &trackenv;
	mini->track_env = ft_memalloc(sizeof(t_track));
	mini->env = ft_track(ft_memalloc(sizeof(t_env)), mini->track_env);
}

void	mini_init_cmd(t_mini *mini)
{
	mini->track_cmd = ft_memalloc(sizeof(t_track));
	mini->cmd = ft_track(ft_memalloc(sizeof(t_cmd)), mini->track_cmd);
	mini->cmd->fdin = dup(0);
	mini->cmd->fdout = dup(1);
}

void	mini_position(char **line)
{
	char	*pwd;
	char	*old_pwd;

	old_pwd = mini_get_old_path();
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		if (old_pwd != NULL)
			pwd = ft_strdup(old_pwd);
		else
		{
			pwd = NULL;
			return ;
		}
	}
	*line = readline("minishell ─❯ ");
	mini_free_pwd(&pwd, &old_pwd);
}
