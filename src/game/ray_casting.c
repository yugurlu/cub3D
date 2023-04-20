/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:02:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/20 16:41:59 by yugurlu          ###   ########.fr       */
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
	int	lineHeight;

	if (cub3d->game.side == 0)
		cub3d->game.perpWallDist = cub3d->game.sideDistX
			- cub3d->game.deltaDistX;
	else
		cub3d->game.perpWallDist = cub3d->game.sideDistY
			- cub3d->game.deltaDistY;
	//printf("perpWallDist: %f", cub3d->game.perpWallDist);
	lineHeight = (int)(1080 / cub3d->game.perpWallDist);
	//printf("lineHeight: %d", lineHeight);
	cub3d->game.drawStart = -lineHeight / 2 + 1080 / 2;
	if (cub3d->game.drawStart < 0)
		cub3d->game.drawStart = 0;
	cub3d->game.drawEnd = lineHeight / 2 + 1080 / 2;
	if (cub3d->game.drawEnd >= 1080)
		cub3d->game.drawEnd = 1080 - 1;
}

void	view(t_cub3d *cub3d, int x)
{
	int	start;

	start = cub3d->game.drawStart;
	while (start < cub3d->game.drawEnd)
	{
		cub3d->mlx.mlx_object_data[start * 1920 + x] = 0x00FF00;
		start++;
	}
}

void fps(t_cub3d *cub3d)
{
	clock_t end;
	double timeFrame;

	end = clock();
	timeFrame = ((double) (end - cub3d->game.time)) / CLOCKS_PER_SEC;
	timeFrame = 1.0 / timeFrame;
	//printf("FPS: %f\n", timeFrame);
	cub3d->game.time = end;
	cub3d->game.fps = timeFrame;
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
		//printf("camx = %f\n", cub3d->game.cameraX);
		//printf("raydirx = %f, raydiry = %f\n", cub3d->game.rayDirX,cub3d->game.rayDirY);
		//printf("deltax = %f, deltay = %f\n", cub3d->game.deltaDistX,cub3d->game.deltaDistY);
		wall(cub3d);
		hit(cub3d);
		//printf("sideDistX: %f\n", cub3d->game.sideDistX);
		//printf("sideDistY: %f\n", cub3d->game.sideDistY);
		i_dont_know_what_i_am_doing_in_this_function(cub3d);
		view(cub3d, x);
		//printf("start = %d, end = %d\n", cub3d->game.drawStart,cub3d->game.drawEnd);
		//getchar();
		x++;
	}
	fps(cub3d);
}
