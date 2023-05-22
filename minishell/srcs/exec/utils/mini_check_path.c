/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_check_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:18:03 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:35 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_exec.h"

static char	*ft_catpath(char *cmd, char *dir)
{
	char	*str;
	int		len;

	len = ft_strlen(dir);
	str = (char *)malloc(sizeof(char) * (len + ft_strlen(cmd) + 2));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, dir, len);
	str[len] = '/';
	len++;
	while (*cmd)
		str[len++] = *cmd++;
	str[len] = '\0';
	return (str);
}

static char	*ft_path(char *cmd, char **env, int i)
{
	char	*path;
	char	*dir;
	char	*tmp;
	char	*bin;

	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = ft_strdup(env[i] + 5);
	tmp = path;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_catpath(cmd, dir);
		free (dir);
		if (access(bin, F_OK) == 0)
		{
			free(tmp);
			return (bin);
		}
		free (bin);
		path += ft_strichr(path, ':') + 1;
	}
	free(tmp);
	return (cmd);
}

char	*checkpath(char **env, char **split, char *key, t_mini *mini)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i] || key[0] == '/' || key[0] == '.')
		str = key;
	else
		str = ft_path(split[0], env, 0);
	if (ft_strncmp(key, str, ft_strlen(str)) == 0)
		return (str);
	else
		ft_track(str, mini->track_cmd);
	return (str);
}
