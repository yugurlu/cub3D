/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:16:08 by bsamli            #+#    #+#             */
/*   Updated: 2023/06/07 18:37:05 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ray_casting(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < 1920)
	{
		cub3d->rc.camerax = 2 * x / (double)1920 - 1;
		cub3d->rc.raydirx = cub3d->rc.dirx + cub3d->rc.planex
			* cub3d->rc.camerax;
		cub3d->rc.raydiry = cub3d->rc.diry + cub3d->rc.planey
			* cub3d->rc.camerax;
		cub3d->rc.mapx = (int)cub3d->rc.posx;
		cub3d->rc.mapy = (int)cub3d->rc.posy;
		cub3d->rc.deltadistx = fabs(1 / cub3d->rc.raydirx);
		cub3d->rc.deltadisty = fabs(1 / cub3d->rc.raydiry);
		direction(cub3d);
		wallhit(cub3d);
		raydist(cub3d);
		texture(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
		cub3d->mlx.mlx_object, 0, 0);
}
