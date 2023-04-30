/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:20:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/30 16:29:14 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_w(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posX + cub3d->rc.dirX
			* 0.07)][(int)(cub3d->rc.posY)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posX + cub3d->rc.dirX
				* 0.07)][(int)(cub3d->rc.posY)]))
		cub3d->rc.posX += cub3d->rc.dirX * 0.07;
	if (cub3d->map.map[(int)cub3d->rc.posX][(int)(cub3d->rc.posY
		+ cub3d->rc.dirY * 0.07)] == '0'
	|| is_character(cub3d->map.map[(int)cub3d->rc.posX][(int)(cub3d->rc.posY
				+ cub3d->rc.dirY * 0.07)]))
		cub3d->rc.posY += cub3d->rc.dirY * 0.07;
}

void	key_s(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posX - cub3d->rc.dirX
			* 0.07)][(int)(cub3d->rc.posY)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posX - cub3d->rc.dirX
				* 0.07)][(int)(cub3d->rc.posY)]))
		cub3d->rc.posX -= cub3d->rc.dirX * 0.07;
	if (cub3d->map.map[(int)(cub3d->rc.posX)][(int)(cub3d->rc.posY
			- cub3d->rc.dirY * 0.07)] == '0'
	|| is_character(cub3d->map.map[(int)(cub3d->rc.posX)][(int)(cub3d->rc.posY
				- cub3d->rc.dirY * 0.07)]))
		cub3d->rc.posY -= cub3d->rc.dirY * 0.07;
}

void	key_a(t_cub3d *cub3d)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cub3d->rc.dirX;
	cub3d->rc.dirX = cub3d->rc.dirX * cos(-0.03) - cub3d->rc.dirY * sin(-0.03);
	cub3d->rc.dirY = old_dirx * sin(-0.03) + cub3d->rc.dirY * cos(-0.03);
	old_planex = cub3d->rc.planeX;
	cub3d->rc.planeX = cub3d->rc.planeX * cos(-0.03) - cub3d->rc.planeY
		* sin(-0.03);
	cub3d->rc.planeY = old_planex * sin(-0.03) + cub3d->rc.planeY * cos(-0.03);
}

void	key_d(t_cub3d *cub3d)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cub3d->rc.dirX;
	cub3d->rc.dirX = cub3d->rc.dirX * cos(0.03) - cub3d->rc.dirY * sin(0.03);
	cub3d->rc.dirY = old_dirx * sin(0.03) + cub3d->rc.dirY * cos(0.03);
	old_planex = cub3d->rc.planeX;
	cub3d->rc.planeX = cub3d->rc.planeX * cos(0.03) - cub3d->rc.planeY
		* sin(0.03);
	cub3d->rc.planeY = old_planex * sin(0.03) + cub3d->rc.planeY * cos(0.03);
}

void	move(t_cub3d *cub3d)
{
	if (cub3d->rc.key_w)
		key_w(cub3d);
	if (cub3d->rc.key_s)
		key_s(cub3d);
	if (cub3d->rc.key_a)
		key_a(cub3d);
	if (cub3d->rc.key_d)
		key_d(cub3d);
}
