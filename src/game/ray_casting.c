/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:02:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/07 18:57:23 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	direction(t_cub3d *cub3d)
{
	if (cub3d->rc.raydirx < 0)
	{
		cub3d->rc.stepx = -1;
		cub3d->rc.sidedistx = (cub3d->rc.posx - cub3d->rc.mapx)
			* cub3d->rc.deltadistx;
	}
	else
	{
		cub3d->rc.stepx = 1;
		cub3d->rc.sidedistx = (cub3d->rc.mapx + 1.0 - cub3d->rc.posx)
			* cub3d->rc.deltadistx;
	}
	if (cub3d->rc.raydiry < 0)
	{
		cub3d->rc.stepy = -1;
		cub3d->rc.sidedisty = (cub3d->rc.posy - cub3d->rc.mapy)
			* cub3d->rc.deltadisty;
	}
	else
	{
		cub3d->rc.stepy = 1;
		cub3d->rc.sidedisty = (cub3d->rc.mapy + 1.0 - cub3d->rc.posy)
			* cub3d->rc.deltadisty;
	}
}

void	wallhit(t_cub3d *cub3d)
{
	cub3d->rc.wall = 0;
	while (!cub3d->rc.wall)
	{
		if (cub3d->rc.sidedistx < cub3d->rc.sidedisty)
		{
			cub3d->rc.sidedistx += cub3d->rc.deltadistx;
			cub3d->rc.mapx += cub3d->rc.stepx;
			cub3d->rc.side = 0;
		}
		else
		{
			cub3d->rc.sidedisty += cub3d->rc.deltadisty;
			cub3d->rc.mapy += cub3d->rc.stepy;
			cub3d->rc.side = 1;
		}
		if (cub3d->map.map[cub3d->rc.mapx][cub3d->rc.mapy] == '1')
			cub3d->rc.wall = 1;
	}
}

void	raydist(t_cub3d *cub3d)
{
	if (cub3d->rc.side == 0)
		cub3d->rc.perpwalldist = cub3d->rc.sidedistx - cub3d->rc.deltadistx;
	else
		cub3d->rc.perpwalldist = cub3d->rc.sidedisty - cub3d->rc.deltadisty;
	cub3d->rc.lineheight = (int)(1080 / cub3d->rc.perpwalldist);
	cub3d->rc.drawstart = -cub3d->rc.lineheight / 2 + 1080 / 2;
	if (cub3d->rc.drawstart < 0)
		cub3d->rc.drawstart = 0;
	cub3d->rc.drawend = cub3d->rc.lineheight / 2 + 1080 / 2;
	if (cub3d->rc.drawend >= 1080)
		cub3d->rc.drawend = 1080 - 1;
}

void	set_value(t_cub3d *cub3d)
{
	double	wallx;

	cub3d->rc.texnum = cub3d->map.map[cub3d->rc.mapx][cub3d->rc.mapy] - 1;
	if (cub3d->rc.side == 0)
		wallx = cub3d->rc.posy + cub3d->rc.perpwalldist * cub3d->rc.raydiry;
	else
		wallx = cub3d->rc.posx + cub3d->rc.perpwalldist * cub3d->rc.raydirx;
	wallx -= floor(wallx);
	cub3d->rc.tex_x = (int)(wallx * (double)64);
	if (cub3d->rc.side == 0 && cub3d->rc.raydirx > 0)
		cub3d->rc.tex_x = 64 - cub3d->rc.tex_x - 1;
	if (cub3d->rc.side == 1 && cub3d->rc.raydiry < 0)
		cub3d->rc.tex_x = 64 - cub3d->rc.tex_x - 1;
	cub3d->rc.texstep = 1.0 * 64 / cub3d->rc.lineheight;
	cub3d->rc.texpos = (cub3d->rc.drawstart - 1080 / 2 + cub3d->rc.lineheight
			/ 2) * cub3d->rc.texstep;
}

void	texture(t_cub3d *cub3d, int x)
{
	int texy;
	
	int	start;

	start = cub3d->rc.drawstart;
	while (start < cub3d->rc.drawend)
	{
		texy = (int)cub3d->rc.texpos & 63;
		cub3d->rc.texpos += cub3d->rc.texstep;
		cub3d->mlx.mlx_object_data[start * 1920 + x] = cub3d->assets.no_data[64 * texy + cub3d->rc.tex_x];
		start++;
	}
}
