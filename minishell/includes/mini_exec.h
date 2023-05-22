/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:46:07 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/22 09:55:31 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXEC_H
# define MINI_EXEC_H

# include "mini_struct.h"
# include "minishell.h"
# include <stdbool.h>

void	ft_exec(t_mini *mini, t_list *tmp);
int		ft_redir(t_list *lst, t_list *cmd);

void	ft_execbuiltin(t_list *cmd, pid_t pid, t_env *env, t_mini *mini);
void	ft_execbuiltinpipe(t_list *cmd, int	*pfd, t_env *ennv, t_mini *mini);
void	ft_execbuiltinn(t_list *cmd, int *pfd, t_cmd *s, t_mini *mini);
void	ft_usebuiltin(char *str, t_env *env, t_mini *mini);
void	mini_pre_heredoc(t_list **lst);
void	ft_execcmd(t_cmd *cmd, char **env, t_env *ennv, t_mini *mini);
void	ft_execcmdpipe(t_list *cmd, char **ev, int	*pfd, t_mini *mini);

/* Utils */
int		ft_checkifredir(t_list **lst);
void	ft_scotchredir(t_list *cmd, char *path, char **split, char **ev);
void	ft_scotch_sign(t_env *env, pid_t pid);
void	ft_scotch_sign_with_pfd(t_env *env, pid_t pid, int *pfd);
char	*checkpath(char **env, char **split, char *key, t_mini *mini);
int		ft_lstsize_env(t_list *lst);
void	mini_not_found(t_cmd *cmd, t_env *env, char *path);
char	**ft_trad(t_env *env);

#endif
