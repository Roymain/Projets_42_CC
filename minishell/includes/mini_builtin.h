/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:43 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/22 10:15:26 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BUILTIN_H
# define MINI_BUILTIN_H

# include <stdio.h>
# include <stdbool.h> 
# include "mini_struct.h"

typedef enum e_errors
{
	NOT_VALID,
	REQUIERED_NUMERIC,
	NO_SUCH_FILE,
	NO_HOME
}			t_errors;

void		builtin_env(t_env *env);
void		builtin_pwd(t_env *env);
void		builtin_unset(t_env *env, char *key);
void		builtin_echo(char *str, t_env *env);
void		builtin_export(t_env *env, char *export);
void		builtin_cd(t_env *env, char *dir, bool choice, t_mini *mini);
void		builtin_dollar(t_env *env);
char		*mini_get_old_path(void);

/* mini_env/tils */

bool		ft_isitbuiltin(const char *str);
int			mini_content_equal(char *str, char c);
void		mini_display_exit_error(int error, const char *str, t_env *env);
void		mini_display_export_error(int error);
void		mini_free_pwd(char **pwd, char **old);

/* List */

t_list		*ft_lstsort(t_list *begin_list, int i, int j, int size);
void		ft_lstsortswap(void *save, void *savee, t_list *current);
t_list		*ft_lstmapp(t_list *lst);
int			print_list(t_list *list);

/* Shell level */
bool		mini_shell_level(const char *str, t_env *env);

/* Utils */
void		mini_export_modif(t_list *list, const char *content);
char		*mini_add(const char *str, uint64_t shellv);
uint64_t	mini_atoi(const char *str);

#endif
