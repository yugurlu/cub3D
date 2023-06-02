/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:20:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/02 11:41:49 by bsamli           ###   ########.fr       */
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

void key_a(t_cub3d *cub3d)
{
    if (cub3d->map.map[(int)(cub3d->rc.posX - cub3d->rc.dirY * 0.07)][(int)(cub3d->rc.posY)] == '0'
        || is_character(cub3d->map.map[(int)(cub3d->rc.posX - cub3d->rc.dirY * 0.07)][(int)(cub3d->rc.posY)]))
        cub3d->rc.posX -= cub3d->rc.dirY * 0.07;
    if (cub3d->map.map[(int)(cub3d->rc.posX)][(int)(cub3d->rc.posY + cub3d->rc.dirX * 0.07)] == '0'
        || is_character(cub3d->map.map[(int)(cub3d->rc.posX)][(int)(cub3d->rc.posY + cub3d->rc.dirX * 0.07)]))
        cub3d->rc.posY += cub3d->rc.dirX * 0.07;
}

void key_d(t_cub3d *cub3d)
{
    if (cub3d->map.map[(int)(cub3d->rc.posX + cub3d->rc.dirY * 0.07)][(int)(cub3d->rc.posY)] == '0'
        || is_character(cub3d->map.map[(int)(cub3d->rc.posX + cub3d->rc.dirY * 0.07)][(int)(cub3d->rc.posY)]))
        cub3d->rc.posX += cub3d->rc.dirY * 0.07;
    if (cub3d->map.map[(int)(cub3d->rc.posX)][(int)(cub3d->rc.posY - cub3d->rc.dirX * 0.07)] == '0'
        || is_character(cub3d->map.map[(int)(cub3d->rc.posX)][(int)(cub3d->rc.posY - cub3d->rc.dirX * 0.07)]))
        cub3d->rc.posY -= cub3d->rc.dirX * 0.07;
}

void	key_left(t_cub3d *cub3d)
{
	double	value;
	double	old_dirx;
	double	old_planex;

	value = -0.03;
	if (cub3d->map.user_type == 'E' || cub3d->map.user_type == 'W')
		value = 0.03;
	old_dirx = cub3d->rc.dirX;
	cub3d->rc.dirX = cub3d->rc.dirX * cos(value) - cub3d->rc.dirY * sin(value);
	cub3d->rc.dirY = old_dirx * sin(value) + cub3d->rc.dirY * cos(value);
	old_planex = cub3d->rc.planeX;
	cub3d->rc.planeX = cub3d->rc.planeX * cos(value) - cub3d->rc.planeY
		* sin(value);
	cub3d->rc.planeY = old_planex * sin(value) + cub3d->rc.planeY * cos(value);
}

void handleMouseMovement(int mouseX, int mouseY, t_cub3d *cub3d) {
    int mouseDiffY = mouseY - cub3d->rc.user_y;

    cub3d->rc.posX += cub3d->rc.dirX * mouseDiffY * 0.01;
    cub3d->rc.posY += cub3d->rc.dirY * mouseDiffY * 0.01;

    cub3d->rc.user_x = mouseX;
    cub3d->rc.user_y = mouseY;
}

void	key_right(t_cub3d *cub3d)
{
	double	value;
	double	old_dirx;
	double	old_planex;

	value = 0.03;
	if (cub3d->map.user_type == 'E' || cub3d->map.user_type == 'W')
		value = -0.03;
	old_dirx = cub3d->rc.dirX;
	cub3d->rc.dirX = cub3d->rc.dirX * cos(value) - cub3d->rc.dirY * sin(value);
	cub3d->rc.dirY = old_dirx * sin(value) + cub3d->rc.dirY * cos(value);
	old_planex = cub3d->rc.planeX;
	cub3d->rc.planeX = cub3d->rc.planeX * cos(value) - cub3d->rc.planeY
		* sin(value);
	cub3d->rc.planeY = old_planex * sin(value) + cub3d->rc.planeY * cos(value);
}

void	move(t_cub3d *cub3d)
{
	if (cub3d->rc.key_w)
		key_w(cub3d);
	if (cub3d->rc.key_s)
		key_s(cub3d);
	if (cub3d->rc.key_left)
		key_left(cub3d);
	if (cub3d->rc.key_right)
		key_right(cub3d);
	if(cub3d->rc.key_a)
		key_a(cub3d);
	if(cub3d->rc.key_d)
		key_d(cub3d);
}
