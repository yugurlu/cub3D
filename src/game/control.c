/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:42:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/20 10:26:22 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int *control(int key, t_cub3d *cub3d)
{
	(void)cub3d;
	if(key == 13)
	{
		cub3d->game.posX += cub3d->game.dirX * 0.1;
		cub3d->game.posY += cub3d->game.dirY * 0.1;
	}
	if(key == 1)
	{
		cub3d->game.posX -= cub3d->game.dirX * 0.1;
		cub3d->game.posY -= cub3d->game.dirY * 0.1;
	}
	if (key == 0)
	{
		double oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(-0.1) - cub3d->game.dirY * sin(-0.1);
		cub3d->game.dirY = oldDirX * sin(-0.1) + cub3d->game.dirY * cos(-0.1);
		double oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(-0.1) - cub3d->game.planeY * sin(-0.1);
		cub3d->game.planeY = oldPlaneX * sin(-0.1) + cub3d->game.planeY * cos(-0.1);
	}
	if (key == 2)
	{
		double oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(0.1) - cub3d->game.dirY * sin(0.1);
		cub3d->game.dirY = oldDirX * sin(0.1) + cub3d->game.dirY * cos(0.1);
		double oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(0.1) - cub3d->game.planeY * sin(0.1);
		cub3d->game.planeY = oldPlaneX * sin(0.1) + cub3d->game.planeY * cos(0.1);
	}
	return (0);
}
