/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:16:28 by bsamli            #+#    #+#             */
/*   Updated: 2023/06/12 18:36:13 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	control(t_cub3d *cub3d)
{
	cub3d->rc.key_left = 0;
	cub3d->rc.key_s = 0;
	cub3d->rc.key_right = 0;
	cub3d->rc.key_w = 0;
}

void	set_variables(t_cub3d *cub3d)
{
	img(cub3d);
	user_location(cub3d);
	camera(cub3d);
	control(cub3d);
}

void	camera1(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)cub3d->rc.posx][(int)cub3d->rc.posy] == 'W')
	{
		cub3d->rc.dirx = 0;
		cub3d->rc.diry = -1;
		cub3d->rc.planex = -0.66;
		cub3d->rc.planey = 0;
	}
	if (cub3d->map.map[(int)cub3d->rc.posx][(int)cub3d->rc.posy] == 'E')
	{
		cub3d->rc.dirx = 0;
		cub3d->rc.diry = 1;
		cub3d->rc.planex = 0.66;
		cub3d->rc.planey = 0;
	}
}

void	camera(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)cub3d->rc.posx][(int)cub3d->rc.posy] == 'N')
	{
		cub3d->rc.dirx = -1;
		cub3d->rc.diry = 0;
		cub3d->rc.planex = 0;
		cub3d->rc.planey = -0.66;
	}
	if (cub3d->map.map[(int)cub3d->rc.posx][(int)cub3d->rc.posy] == 'S')
	{
		cub3d->rc.dirx = 1;
		cub3d->rc.diry = 0;
		cub3d->rc.planex = 0;
		cub3d->rc.planey = 0.66;
	}
	camera1(cub3d);
}
