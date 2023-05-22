/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:39:54 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:44:00 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_builtin.h"

void	mini_free_pwd(char **pwd, char **old)
{
	if (*pwd)
	{
		free(*pwd);
		*pwd = NULL;
	}
	if (*old)
	{
		free(*old);
		*old = NULL;
	}
}

char	*mini_get_old_path(void)
{
	char		*pwd;
	static char	*old_pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		if (old_pwd)
		{
			free(old_pwd);
			old_pwd = NULL;
		}
		old_pwd = ft_strdup(pwd);
		return (pwd);
	}
	if (old_pwd != NULL && pwd == NULL)
	{
		pwd = ft_strdup(old_pwd);
		return (pwd);
	}
	return (NULL);
}

void	builtin_pwd(t_env *env)
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
	printf("%s\n", pwd);
	mini_free_pwd(&pwd, &old_pwd);
	env->return_value = 0;
}
