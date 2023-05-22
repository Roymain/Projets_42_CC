/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:38:34 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:43:28 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_builtin.h"

static int	ft_strcmp_expert(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] != '=')
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (s1[i] == '=' && !s2[i])
		return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static void	mini_display_cd_error(t_env *env, int error, const char *dir)
{
	if (error == NO_HOME)
		printf("minishell: cd: HOME not set\n");
	else if (error == NO_SUCH_FILE)
		printf("cd: %s: No such file or directory\n", dir);
	env->return_value = 1;
}

static char	*mini_find_home(t_list *tmp, t_env *env)
{
	char	*home_value;

	home_value = NULL;
	while (tmp)
	{
		if (ft_strcmp_expert(tmp->key, "HOME") == 0)
		{
			home_value = ft_strdup(tmp->content);
			return (home_value);
		}
		tmp = tmp->next;
	}
	if (home_value == NULL)
		mini_display_cd_error(env, NO_HOME, NULL);
	else
		free(home_value);
	return (NULL);
}

static bool	mini_check_cd(t_env *env, t_list *tmp, bool choice, char **dir)
{
	if (choice == true)
	{
		*dir = mini_find_home(tmp, env);
		if (*dir == NULL)
			return (false);
	}
	return (true);
}

void	builtin_cd(t_env *env, char *dir, bool choice, t_mini *mini)
{
	t_list	*tmp;
	char	*old;

	if (mini_check_cd(env, env->list, choice, &dir) == false)
		return ;
	tmp = env->list;
	old = mini_get_old_path();
	if (chdir(dir) == 0)
	{
		while (ft_strncmp(env->list->key, "OLDPWD", 7) != 0)
			env->list = env->list->next;
		env->list->content = ft_track(ft_strdup(old), mini->track_env);
		env->list = tmp;
		while (ft_strncmp(env->list->key, "PWD", 3) != 0)
			env->list = env->list->next;
		env->list->content = ft_track(getcwd(NULL, 0), mini->track_env);
		env->list = tmp;
		env->return_value = 0;
	}
	else
		mini_display_cd_error(env, NO_SUCH_FILE, dir);
	if (choice == true)
		free(dir);
	free(old);
}
