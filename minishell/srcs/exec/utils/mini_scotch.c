/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_scotch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:12:16 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:50 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_exec.h"

static void	mini_close_fd(int *pfd)
{
	close(pfd[1]);
	close(pfd[0]);
}

void	ft_scotch_sign_with_pfd(t_env *env, pid_t pid, int *pfd)
{
	mini_close_fd(pfd);
	waitpid(pid, &env->status, 0);
	if (WIFEXITED(env->status))
		env->return_value = WEXITSTATUS(env->status);
	else
		env->return_value = 1;
}

void	ft_scotch_sign(t_env *env, pid_t pid)
{
	waitpid(pid, &env->status, 0);
	if (WIFEXITED(env->status))
		env->return_value = WEXITSTATUS(env->status);
	else
		env->return_value = 1;
}

void	ft_scotchredir(t_list *cmd, char *path, char **split, char **ev)
{
	int	i;

	i = 0;
	if (cmd->key[0] != '\0')
	{
		if (cmd->redir)
			i = ft_redir(cmd->redir, cmd);
		if (i == 0)
		{
			execve(path, split, ev);
			perror("minishell");
		}
	}
	exit (EXIT_FAILURE);
}
