/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:12:05 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/31 04:43:55 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCT_H
# define MINI_STRUCT_H

# include "../libft/includes/libft.h"
# include "../srcs/utils/tracker/include/tracker.h"
# include <signal.h>
# include <sys/types.h>

typedef struct s_sig
{
	int		si_signo;
	int		si_errno;
	int		si_code;
	pid_t	si_pid;
	uid_t	si_uid;
	int		si_status;
	clock_t	si_utime;
	clock_t	si_stime;
	int		si_int;
	void	*si_ptr;
	void	*si_addr;
	int		si_band;
	int		si_fd;
}			t_siginfo;

typedef struct s_cmd
{
	int			fdin;
	int			fdout;
	int			dernierfork;
	int			status;
	t_list		*listcmd;
}			t_cmd;

typedef struct s_env
{
	t_list	*list;
	int		status;
	int		return_value;
}			t_env;

typedef struct s_mini
{
	struct s_sig	*siginfo;
	struct s_cmd	*cmd;
	struct s_env	*env;
	struct s_track	*track_env;
	struct s_track	*track_cmd;
	int				return_value;
}				t_mini;

#endif
