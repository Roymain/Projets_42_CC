/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_str_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:46:06 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:03:14 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/mini_exec.h"
#include <limits.h>

static int	mini_check_level(uint64_t shellv)
{
	if (shellv >= INT_MAX || shellv < 0)
		return (0);
	else if (shellv <= INT_MAX - 1 && shellv > 999)
		return (1);
	else if (shellv == 999)
		return (-1);
	else if (shellv < 999)
		return (shellv);
	return (shellv);
}

static char	*mini_level_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, len + 1);
	return (dest);
}

static void	mini_level_error(uint64_t shellv, int *shell_value)
{
	if (*shell_value == 1)
	{
		printf("minishell ─❯ warning: shell level (%llu)", shellv + 1);
		printf("too high, resetting to 1\n");
	}
	else
		printf("");
}

static char	*mini_value_to_return(const char *str)
{
	char	*new_shellv;

	new_shellv = NULL;
	new_shellv = ft_strdup(str);
	return (new_shellv);
}

char	*mini_add(const char *str, uint64_t shellv)
{
	char	*new_shellv;
	char	*get_value;
	int		shell_value;

	shell_value = mini_check_level(shellv);
	if (shell_value != (int)shellv && shell_value > -1)
		mini_level_error(shellv, &shell_value);
	else if (shellv == 0 && shell_value == 0)
		return (mini_value_to_return("SHLVL=0"));
	else if (shell_value == -1)
		return (mini_value_to_return("SHLVL="));
	if (shell_value != (int)shellv)
		get_value = ft_itoa(shell_value);
	else
		get_value = ft_itoa(shell_value + 1);
	new_shellv = mini_level_strjoin(str, get_value);
	free(get_value);
	get_value = NULL;
	return (new_shellv);
}
