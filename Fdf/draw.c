/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:28:17 by rcuminal          #+#    #+#             */
/*   Updated: 2021/12/11 14:13:05 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	ft_draw_line(t_fdf *fdf)
{
	fdf->var.deltax = fdf->pos.endx - fdf->pos.beginx;
	fdf->var.deltay = fdf->pos.endy - fdf->pos.beginy ;
	fdf->var.pixels = sqrt((fdf->var.deltax * fdf->var.deltax)
			+ (fdf->var.deltay * fdf->var.deltay));
	fdf->var.deltax /= fdf->var.pixels;
	fdf->var.deltay /= fdf->var.pixels;
	fdf->var.pixelx = fdf->pos.beginx;
	fdf->var.pixely = fdf->pos.beginy ;
	while (fdf->var.pixels)
	{
		mlx_pixel_put(fdf->mlx, fdf->mlxwin, fdf->var.pixelx,
			fdf->var.pixely, fdf->pos.color);
		fdf->var.pixelx += fdf->var.deltax;
		fdf->var.pixely += fdf->var.deltay;
		--fdf->var.pixels;
	}
	return ;
}

void	xplus(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y--;
	if (fdf->y >= 0)
		fdf->coeff = fdf->pars[fdf->y][fdf->x];
	fdf->pos.beginx = fdf->pos.scrw / 2
		+ (fdf->pos.espx * (fdf->maxy - 1 - fdf->y));
	fdf->pos.beginy = (fdf->pos.scrh / 16 * 15
			- (fdf->pos.espy * (fdf->maxy - 1 - fdf->y + fdf->coeff)));
}

void	drawx(t_fdf *fdf)
{
	while (fdf->y >= 0)
	{
		while (fdf->x < fdf->maxx - 1)
		{
			fdf->coeff = fdf->pars[fdf->y][fdf->x + 1]
				- fdf->pars[fdf->y][fdf->x];
			if (fdf->coeff < 0)
				fdf->coeff = -fdf->coeff;
			fdf->pos.endx = fdf->pos.beginx - fdf->pos.espx;
			if (fdf->pars[fdf->y][fdf->x] > fdf->pars[fdf->y][fdf->x + 1])
				fdf->pos.endy = fdf->pos.beginy
					- fdf->pos.espy + fdf->pos.espy * fdf->coeff;
			if (fdf->pars[fdf->y][fdf->x] < fdf->pars[fdf->y][fdf->x + 1])
				fdf->pos.endy = fdf->pos.beginy
					- fdf->pos.espy - fdf->pos.espy * fdf->coeff ;
			if (fdf->pars[fdf->y][fdf->x] == fdf->pars[fdf->y][fdf->x + 1])
				fdf->pos.endy = fdf->pos.beginy - fdf->pos.espy;
			fdf->pos.color = 0xFFFFFF;
			ft_draw_line(fdf);
			fdf->pos.beginx = fdf->pos.endx;
			fdf->pos.beginy = fdf->pos.endy;
			fdf->x++;
		}
		xplus(fdf);
	}
}

void	yplus(t_fdf	*fdf)
{
	fdf->y = fdf->maxy - 1;
		fdf->x++;
		fdf->coeff = fdf->pars[fdf->y][fdf->x];
		fdf->pos.beginx = fdf->pos.scrw / 2 - (fdf->pos.espx * fdf->x);
		fdf->pos.beginy = (fdf->pos.scrh / 16 * 15
			- (fdf->pos.espy * (fdf->x + fdf->coeff)));
}

void	drawy(t_fdf *fdf)
{
	while (fdf->x <= fdf->maxx - 1)
	{
		while (fdf->y > 0)
		{
			fdf->coeff = fdf->pars[fdf->y][fdf->x]
				- fdf->pars[fdf->y - 1][fdf->x];
			if (fdf->coeff < 0)
				fdf->coeff = -fdf->coeff;
			fdf->pos.endx = fdf->pos.beginx + fdf->pos.espx;
			if (fdf->pars[fdf->y][fdf->x] > fdf->pars[fdf->y - 1][fdf->x])
				fdf->pos.endy = fdf->pos.beginy
					- fdf->pos.espy + fdf->pos.espy * fdf->coeff;
			if (fdf->pars[fdf->y][fdf->x] < fdf->pars[fdf->y - 1][fdf->x])
				fdf->pos.endy = fdf->pos.beginy
					- fdf->pos.espy - fdf->pos.espy * fdf->coeff;
			if (fdf->pars[fdf->y][fdf->x] == fdf->pars[fdf->y - 1][fdf->x])
				fdf->pos.endy = fdf->pos.beginy - fdf->pos.espy;
			fdf->pos.color = 0xFFFFFF;
			ft_draw_line(fdf);
			fdf->pos.beginx = fdf->pos.endx;
			fdf->pos.beginy = fdf->pos.endy;
			fdf->y--;
		}
		yplus(fdf);
	}
}
