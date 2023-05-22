/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_single_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:28:29 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:00:34 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*mini_do_loop_simple(int *j, char *str, char *tmp)
{
	while (str[*j] && str[*j] != '\'')
	{
		tmp[*j - 1] = str[*j];
		*j += 1;
	}
	return (tmp);
}

char	*ft_simple(char *str, int *i)
{
	char	*tmp;
	int		j;

	j = -1;
	tmp = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[++j] && j < *i)
		tmp[j] = str[j];
	j++;
	tmp = mini_do_loop_simple(&j, str, tmp);
	*i = j - 2;
	if (!str[j])
	{
		tmp[j - 1] = 0;
		return (tmp);
	}
	j++;
	while (str[j] != '\0')
	{
		tmp[j - 2] = str[j];
		j++;
	}
	tmp[j - 2] = '\0';
	return (tmp);
}
