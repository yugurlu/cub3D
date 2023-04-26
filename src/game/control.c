/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:42:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/26 14:38:51 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int close_window(int key, void *cub3d)
{
	(void)key;
	(void)cub3d;
	//system("leaks cub3D");
	exit(0);
}

int control(int key, void *cub3dd)
{
	double oldDirX;
	double oldPlaneX;
	t_cub3d *cub3d = (t_cub3d *)cub3dd;
	if(key == 13)
	{
		if(cub3d->map_info.map[(int)(cub3d->game.posX + cub3d->game.dirX * 0.2)][(int)(cub3d->game.posY)] == '0')
			cub3d->game.posX += cub3d->game.dirX * 0.2;
		if(cub3d->map_info.map[(int)cub3d->game.posX][(int)(cub3d->game.posY + cub3d->game.dirY * 0.2)] == '0')
			cub3d->game.posY += cub3d->game.dirY * 0.2;
	}
	if(key == 1)
	{
		if(cub3d->map_info.map[(int)(cub3d->game.posX - cub3d->game.dirX * 0.2)][(int)(cub3d->game.posY)] == '0')
			cub3d->game.posX -= cub3d->game.dirX * 0.2;
		if(cub3d->map_info.map[(int)(cub3d->game.posX)][(int)(cub3d->game.posY - cub3d->game.dirY * 0.2)] == '0')
			cub3d->game.posY -= cub3d->game.dirY * 0.2;
	}
	if (key == 0)
	{
		oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(-0.1) - cub3d->game.dirY * sin(-0.1);
		cub3d->game.dirY = oldDirX * sin(-0.1) + cub3d->game.dirY * cos(-0.1);
		double oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(-0.1) - cub3d->game.planeY * sin(-0.1);
		cub3d->game.planeY = oldPlaneX * sin(-0.1) + cub3d->game.planeY * cos(-0.1);
	}
	if (key == 2)
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