/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:46:07 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 23:27:06 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "proto.h"

u_int32_t	**ft_mem2array(uint32_t *mem, size_t len_x, size_t len_y)
{
	u_int32_t	**arr;
	size_t		i;

	arr = malloc(len_y * sizeof(u_int32_t *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_y)
	{
		arr[i] = &(mem[i * len_x]);
		++i;
	}
	return (arr);
}

int	ft_errorimg_norm(t_cub *cub, int i, mlx_ptr_t *new_mlx)
{
	if (i == 0){
		free_parsed(cub->pars);
		return (1);
	}
	if (i == 1)
	{
		mlx_destroy_image(cub->mlx, new_mlx->font);
		mlx_destroy_window(cub->mlx, cub->mlxwin);
		free(cub->mlx);
		free_parsed(cub->pars);
		return (1);
	}
	return (0);
}

int	ft_errorimg(t_cub *cub, int i)
{
	mlx_ptr_t	*new_mlx;
	int			j;

	new_mlx = cub->mlx;
	j = 0;
	if (i == 0 || i == 1)
		return (ft_errorimg_norm(cub, i, new_mlx));
	while (j < i && j <= 2)
	{
		mlx_destroy_image(cub->mlx, cub->image[j].img);
		free(cub->image[j].arr);
		j++;
	}
	while (j < i - 1)
	{
		mlx_destroy_image(cub->mlx, cub->texture[j - 3].img);
		free(cub->texture[j - 3].arr);
		j++;
	}
	mlx_destroy_image(cub->mlx, new_mlx->font);
	mlx_destroy_window(cub->mlx, cub->mlxwin);
	free(cub->mlx);
	free_parsed(cub->pars);
	return (1);
}
