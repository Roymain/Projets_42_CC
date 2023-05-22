/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:08:03 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/18 04:14:40 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		ft_strlen(char *theString);
char	*get_next_line(int fd);
void	*ft_calloc( size_t elementCount, size_t elementSize);
char	*ft_replace(char *buffer, int i);
int		ft_checkn(char *buffer, char c);
char	*ft_realloc(char *strr, int i, char *buffer);
#endif