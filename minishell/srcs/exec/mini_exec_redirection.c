/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:02:32 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:25 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_exec.h"

static char	*mini_no_back(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			str[i] = ' ';
		i++;
	}
	return (str);
}

static int	ft_redirdouble(int fd, t_list *list, t_list *cmd)
{
	fd = open(mini_no_back(list->content),
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	cmd->fdout = dup(1);
	dup2(fd, 1);
	return (fd);
}

static int	ft_redirsimple(int fd, t_list *list, t_list *cmd)
{
	fd = open(mini_no_back(list->content),
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd->fdout = dup(1);
	dup2(fd, 1);
	return (fd);
}

static int	cut_redir(int fd, t_list *cmd, char *content)
{
	cmd->fdin = dup(0);
	fd = open(mini_no_back(content), O_RDONLY, 0644);
	if (fd != -1)
		dup2(fd, 0);
	else
		return (printf("minishell: %s: No such file or directory\n",
				mini_no_back(content)));
	return (0);
}

int	ft_redir(t_list *lst, t_list *cmd)
{
	int		fd;
	t_list	*list;

	while (lst->prev)
		lst = lst->prev;
	list = lst;
	cmd->fdout = dup(1);
	while (list)
	{
		if (ft_strncmp(list->key, ">", ft_strlen(list->key)) == 0)
			fd = ft_redirsimple(fd, list, cmd);
		else if (ft_strncmp(list->key, ">>", ft_strlen(list->key)) == 0)
			fd = ft_redirdouble(fd, list, cmd);
		else if (ft_strncmp(list->key, "<", ft_strlen(list->key)) == 0
			&& cut_redir(fd, cmd, list->content) != 0)
			return (1);
		else if (ft_strncmp(list->key, "<<", ft_strlen(list->key)) == 0)
		{
			fd = open(list->content, O_RDONLY, 0644);
			dup2(fd, 0);
		}
		list = list->next;
	}
	return (0);
}
