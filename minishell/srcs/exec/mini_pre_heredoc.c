/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pre_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 05:22:37 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 21:45:29 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_creationheredoc(t_list *lst)
{
	char	*line;
	int		fd;

	fd = open(lst->redir->content,
			O_RDWR | O_CREAT | O_APPEND, 0777);
	line = readline("> ");
	signal(SIGINT, mini_handler);
	while (line && ft_strncmp(line, lst->redir->content,
			ft_strlen(lst->redir->content)) != 0)
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = readline("> ");
	}
	free(line);
}

void	mini_pre_heredoc(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst);
	while ((*lst))
	{
		if ((*lst)->redir)
		{
			while ((*lst)->redir)
			{
				tmp2 = (*lst)->redir;
				if (ft_strncmp((*lst)->redir->key, "<< ", 2) == 0)
					ft_creationheredoc(*lst);
				(*lst)->redir = (*lst)->redir->next;
			}
			(*lst)->redir = tmp2;
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}
