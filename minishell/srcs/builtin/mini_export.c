/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:40:42 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:43:57 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_builtin.h"

static int	ft_strenvcmp(const char *s1, const char *s2)
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

static void	export_modif(t_list *list, char *content)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strenvcmp(content, tmp->key) == 0)
		{
			if (tmp->content && ft_strichr(content, '=') > 0)
			{
				tmp->content = ft_strnndup(content, ft_strichr(content, '\0'),
						ft_strichr(content, '=') + 1);
			}
			else
				tmp->content = NULL;
		}
		tmp = tmp->next;
	}
}

static int	already_in(t_list	*list, char *key)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strenvcmp(key, tmp->key) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	mini_content_to_export(t_env *env, const char *export, t_list **tmp)
{
	*tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')),
			ft_strnndup(export, ft_strichr(export, '\0'),
				ft_strichr(export, '=') + 1));
	ft_lstadd_back(&env->list, *tmp);
}

void	builtin_export(t_env *env, char *export)
{
	t_list	*tmp;

	if (already_in(env->list, export) == 1)
		return (export_modif(env->list, export));
	if (export[ft_strichr(export, '=') - 1] == ' ')
		return (mini_display_export_error(NOT_VALID));
	if (mini_content_equal(export, '=') == 1
		&& export[ft_strichr(export, '=') + 1])
		mini_content_to_export(env, export, &tmp);
	else if (mini_content_equal(export, '=') == 1
		&& !export[ft_strichr(export, '=') + 1])
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')), " ");
		ft_lstadd_back(&env->list, tmp);
	}
	else
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '\0')),
				"\0");
		ft_lstadd_back(&env->list, tmp);
	}
	env->return_value = 0;
}
