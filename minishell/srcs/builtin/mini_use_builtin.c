/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_use_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:42:31 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:44:19 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	mini_display_exit(t_env *env, const char *str)
{
	int	index;
	int	exit_value;

	index = 0;
	exit_value = ft_atoi(str, &index);
	env->return_value = exit_value;
	printf("exit\n");
	if (exit_value > 255)
		exit_value = exit_value % 256;
	exit (exit_value);
}

void	builtin_exit(char *str, t_env *env)
{
	int	index;
	int	i;

	i = -1;
	index = 1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			index = 0;
	if (index == 1)
		mini_display_exit(env, str);
	else
		mini_display_exit_error(REQUIERED_NUMERIC, str, env);
}

void	ft_usebuiltin(char *str, t_env *env, t_mini *mini)
{
	t_list	*export;

	if (ft_strncmp(str, "exit ", 5) == 0)
		builtin_exit(str + 5, env);
	if (ft_strncmp(str, "unset ", 5) == 0)
		builtin_unset(env, str + 6);
	if (ft_strncmp(str, "export ", 7) == 0)
		return (builtin_export(env, str + 7));
	if (ft_strncmp(str, "export", 6) == 0)
	{
		export = ft_lstsort(env->list, 0, 0, 0);
		print_list(export);
		ft_lstclear(&export, &(free));
	}
	if (ft_strncmp(str, "cd ", 3) == 0)
		builtin_cd(env, str + 3, false, mini);
	if (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		builtin_cd(env, NULL, true, mini);
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		builtin_pwd(env);
	if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		builtin_env(env);
	if (ft_strncmp(str, "echo ", ft_strlen("echo ")) == 0)
		builtin_echo(str, env);
}
