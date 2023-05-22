/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:06:25 by rcuminal          #+#    #+#             */
/*   Updated: 2022/06/22 17:08:02 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACKER_H
# define TRACKER_H

# include <stdlib.h>

typedef struct s_track
{
	struct s_track	*next;
	void			*content;
}				t_track;

t_track	*ft_lstnewtracker(void **content);
int		ft_free_all(t_track *tracker);
void	*ft_track_tab(void **tab, t_track *list);
void	*ft_track(void *address, t_track *list);
void	ft_lstcleartracker(t_track **lst, void (*del)(void *));
void	ft_lstadd_backtotrack(t_track **alst, t_track *news);
void	*ft_memallocc(size_t size);

void	mini_list_clear_properly(t_track **lst);

#endif