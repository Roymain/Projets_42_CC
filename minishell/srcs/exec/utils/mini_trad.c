/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_trad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 04:11:42 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:54 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*ft_strjoinequal(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '=';
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_trad(t_env *env)
{
	char	**ev;
	t_list	*list;
	int		i;

	i = 0;
	ev = ft_memalloc(sizeof(char *) * (ft_lstsize_env(env->list) + 1));
	list = env->list;
	while (list)
	{
		if (list->content)
		{
			ev[i] = ft_strjoinequal(list->key, list->content);
			if (!ev[i])
			{
				while (i != 0)
					free(ev[--i]);
				free(ev);
				return (NULL);
			}
			i++;
		}
		list = list->next;
	}
	return (ev);
}
