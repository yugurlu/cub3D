/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:42:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/20 16:36:43 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int *close_window(int key, t_cub3d *cub3d)
{
	(void)key;
	system("leaks cub3D");
	exit(0);
}

int *control(int key, t_cub3d *cub3d)
{
	double oldDirX;
	double oldPlaneX;

	if(key == 13)
	{
		if(cub3d->map_info.map[(int)(cub3d->game.posX + cub3d->game.dirX * 0.1)][(int)(cub3d->game.posY)] == '0')
		{
			cub3d->game.posX += cub3d->game.dirX * 0.1;
			cub3d->game.posY += cub3d->game.dirY * 0.1;
		}
	}
	else if(key == 1)
	{
		if(cub3d->map_info.map[(int)(cub3d->game.posX - cub3d->game.dirX * 0.1)][(int)(cub3d->game.posY)] == '0')
		{
			cub3d->game.posX -= cub3d->game.dirX * 0.1;
			cub3d->game.posY -= cub3d->game.dirY * 0.1;
		}
	}
	else if (key == 0)
	{
		oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(-0.1) - cub3d->game.dirY * sin(-0.1);
		cub3d->game.dirY = oldDirX * sin(-0.1) + cub3d->game.dirY * cos(-0.1);
		double oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(-0.1) - cub3d->game.planeY * sin(-0.1);
		cub3d->game.planeY = oldPlaneX * sin(-0.1) + cub3d->game.planeY * cos(-0.1);
	}
	else if (key == 2)
	{
		oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(0.1) - cub3d->game.dirY * sin(0.1);
		cub3d->game.dirY = oldDirX * sin(0.1) + cub3d->game.dirY * cos(0.1);
		oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(0.1) - cub3d->game.planeY * sin(0.1);
		cub3d->game.planeY = oldPlaneX * sin(0.1) + cub3d->game.planeY * cos(0.1);
	}
	else if (key == 53)
		exit(0);
	return (0);
}
