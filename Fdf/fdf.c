/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:59:32 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/14 03:36:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mapinit(t_fdf *fdf)
{
	fdf->maxx = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->pars = NULL;
	fdf->fd = open(fdf->map, O_RDONLY);
	fdf->maxy = ft_countline(fdf->fd);
	fdf->pars = ft_calloc(fdf->maxy + 1, sizeof(int *));
	fdf->fd = open(fdf->map, O_RDONLY);
	while (fdf->y < fdf->maxy)
	{
		fdf->pars[fdf->y] = ft_parsing(fdf->pars[fdf->y], fdf->fd, &fdf->maxx);
		fdf->y++;
	}
	fdf->y = 0;
	fdf->mlx = mlx_init();
	fdf->pos.scrh = 1080;
	fdf->pos.scrw = 1920;
	fdf->pos.espx = (fdf->pos.scrw / ((fdf->maxy) + (fdf->maxx) * 3));
	if (((fdf->maxy) + (fdf->maxx) * 4) > fdf->pos.scrw)
		fdf->pos.espx = (fdf->pos.scrw / ((fdf->maxy) + (fdf->maxx) / 40));
	fdf->pos.espy = fdf->pos.espx / 2;
	return ;
}

int	closee(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->mlxwin);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		fdf.map = "texte.txt";
	else
		fdf.map = argv[1];
	mapinit(&fdf);
	close(fdf.fd);
	fdf.mlxwin = mlx_new_window(fdf.mlx, fdf.pos.scrw, fdf.pos.scrh, "FdF");
	fdf.y = fdf.maxy - 1 ;
	fdf.x = 0;
	fdf.coeff = fdf.pars[fdf.y][fdf.x];
	fdf.pos.beginx = fdf.pos.scrw / 2;
	fdf.pos.beginy = (fdf.pos.scrh / 16 * 15) - fdf.pos.espy * fdf.coeff ;
	drawx(&fdf);
	fdf.y = fdf.maxy - 1;
	fdf.x = 0;
	fdf.coeff = fdf.pars[fdf.y][fdf.x];
	fdf.pos.beginx = fdf.pos.scrw / 2;
	fdf.pos.beginy = (fdf.pos.scrh / 16 * 15) - fdf.pos.espy * fdf.coeff ;
	drawy(&fdf);
	mlx_key_hook(fdf.mlxwin, closee, &fdf);
	mlx_loop(fdf.mlx);
	free(&fdf);
	return (0);
}
