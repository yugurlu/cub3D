/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:02:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/27 16:59:13 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	wall(t_cub3d *cub3d)
{
	if (cub3d->game.rayDirX < 0)
	{
		cub3d->game.stepX = -1;
		cub3d->game.sideDistX = (cub3d->game.posX - cub3d->game.mapX)
			* cub3d->game.deltaDistX;
	}
	else
	{
		cub3d->game.stepX = 1;
		cub3d->game.sideDistX = (cub3d->game.mapX + 1.0 - cub3d->game.posX)
			* cub3d->game.deltaDistX;
	}
	if (cub3d->game.rayDirY < 0)
	{
		cub3d->game.stepY = -1;
		cub3d->game.sideDistY = (cub3d->game.posY - cub3d->game.mapY)
			* cub3d->game.deltaDistY;
	}
	else
	{
		cub3d->game.stepY = 1;
		cub3d->game.sideDistY = (cub3d->game.mapY + 1.0 - cub3d->game.posY)
			* cub3d->game.deltaDistY;
	}
}

void	hit(t_cub3d *cub3d) //dda algorithm
{
	cub3d->game.wall = 0;
	while (!cub3d->game.wall)
	{
		if (cub3d->game.sideDistX < cub3d->game.sideDistY)
		{
			cub3d->game.sideDistX += cub3d->game.deltaDistX;
			cub3d->game.mapX += cub3d->game.stepX;
			cub3d->game.side = 0;
		}
		else
		{
			cub3d->game.sideDistY += cub3d->game.deltaDistY;
			cub3d->game.mapY += cub3d->game.stepY;
			cub3d->game.side = 1;
		}
		if (cub3d->map_info.map[cub3d->game.mapX][cub3d->game.mapY] == '1')
			cub3d->game.wall = 1;
	}
}

void	i_dont_know_what_i_am_doing_in_this_function(t_cub3d *cub3d)
{
	if (cub3d->game.side == 0)
		cub3d->game.perpWallDist = cub3d->game.sideDistX
			- cub3d->game.deltaDistX;
	else
		cub3d->game.perpWallDist = cub3d->game.sideDistY
			- cub3d->game.deltaDistY;
	cub3d->game.lineHeight = (int)(1080 / cub3d->game.perpWallDist);
	cub3d->game.drawStart = -cub3d->game.lineHeight / 2 + 1080 / 2;
	if (cub3d->game.drawStart < 0)
		cub3d->game.drawStart = 0;
	cub3d->game.drawEnd = cub3d->game.lineHeight / 2 + 1080 / 2;
	if (cub3d->game.drawEnd >= 1080)
		cub3d->game.drawEnd = 1080 - 1;
}


void set_value(t_cub3d *cub3d)
{
	double wallX;
	cub3d->game.texNum = cub3d->map_info.map[cub3d->game.mapX][cub3d->game.mapY] - 1;
	if(cub3d->game.side == 0)
		wallX = cub3d->game.posY + cub3d->game.perpWallDist * cub3d->game.rayDirY;
	else
		wallX = cub3d->game.posX + cub3d->game.perpWallDist * cub3d->game.rayDirX;
	wallX -= floor(wallX);
	cub3d->game.texX = (int)(wallX * (double)64);
	if(cub3d->game.side == 0 && cub3d->game.rayDirX > 0)
		cub3d->game.texX = 64 - cub3d->game.texX - 1;
	if(cub3d->game.side == 1 && cub3d->game.rayDirY < 0)
		cub3d->game.texX = 64 - cub3d->game.texX - 1;
	cub3d->game.texStep = 1.0 * 64 / cub3d->game.lineHeight;
	cub3d->game.texPos = (cub3d->game.drawStart - 1080 / 2 + cub3d->game.lineHeight / 2) * cub3d->game.texStep;
}

void	image(t_cub3d *cub3d, int x)
{
	int texY;
	int	start;

	set_value(cub3d);
	start = cub3d->game.drawStart;
	while (start < cub3d->game.drawEnd)
	{
		texY = (int)cub3d->game.texPos & 63;
		cub3d->game.texPos += cub3d->game.texStep;
		cub3d->mlx.mlx_object_data[start * 1920 + x] = cub3d->assets.NO_data[64 * texY + cub3d->game.texX];
		start++;
	}
}

void	ray_casting(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < 1920)
	{
		cub3d->game.cameraX = 2 * x / (double)1920 - 1;
		cub3d->game.rayDirX = cub3d->game.dirX + cub3d->game.planeX * cub3d->game.cameraX;
		cub3d->game.rayDirY = cub3d->game.dirY + cub3d->game.planeY * cub3d->game.cameraX;
		cub3d->game.mapX = (int)cub3d->game.posX;
		cub3d->game.mapY = (int)cub3d->game.posY;
		cub3d->game.deltaDistX = fabs(1 / cub3d->game.rayDirX);
		cub3d->game.deltaDistY = fabs(1 / cub3d->game.rayDirY);
		wall(cub3d);
		hit(cub3d);
		i_dont_know_what_i_am_doing_in_this_function(cub3d);
		image(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->mlx.mlx_object, 0, 0);
}
