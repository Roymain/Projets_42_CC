/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:21:53 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/13 20:46:20 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pos
{
	int		beginx;
	int		beginy;
	int		endx;
	int		endy;
	int		color;
	int		scrw;
	int		scrh;
	int		espx;
	int		espy;
}					t_pos;

typedef struct s_var
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;
}					t_var;

typedef struct fdf
{
	void	*mlx;
	void	*mlxwin;
	int		**pars;
	char	*map;
	int		x;
	int		y;
	int		fd;
	int		maxx;
	int		maxy;
	double	coeff;
	t_pos	pos;
	t_var	var;
}					t_fdf;

void	ft_draw_line(t_fdf *fdf);
// int		*ft_parsing_color(int *color, int fd);
char	*ft_extractline(char *tab, int fd);
int		ft_countline(int fd);
int		*ft_parsing(int *tab, int fd, int *maxx);
int		ft_atoi_color(char *str, int *i);
void	drawx(t_fdf *fdf);
void	drawy(t_fdf *fdf);

#endif