/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/06/22 15:17:41 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include "../libft/includes/libft.h"
# include "mini_struct.h"
# include "mini_builtin.h"
# include "mini_exec.h"
# include "mini_parsing.h"
# include "../srcs/utils/tracker/include/tracker.h"

/* Utils */

void	mini_quit(int num);
void	mini_handler(int num);
void	mini_position(char **line);
void	mini_init(t_mini *mini, int argc, char **argv);
void	mini_init_cmd(t_mini *mini);

#endif
