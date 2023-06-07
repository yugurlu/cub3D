/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:20:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/07 18:32:00 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_w(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posx + cub3d->rc.dirx
			* 0.07)][(int)(cub3d->rc.posy)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx + cub3d->rc.dirx
				* 0.07)][(int)(cub3d->rc.posy)]))
		cub3d->rc.posx += cub3d->rc.dirx * 0.07;
	if (cub3d->map.map[(int)cub3d->rc.posx][(int)(cub3d->rc.posy
		+ cub3d->rc.diry * 0.07)] == '0'
		|| is_character(cub3d->map.map[(int)cub3d->rc.posx][(int)(cub3d->rc.posy
				+ cub3d->rc.diry * 0.07)]))
		cub3d->rc.posy += cub3d->rc.diry * 0.07;
}

void	key_s(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posx - cub3d->rc.dirx
			* 0.07)][(int)(cub3d->rc.posy)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx - cub3d->rc.dirx
				* 0.07)][(int)(cub3d->rc.posy)]))
		cub3d->rc.posx -= cub3d->rc.dirx * 0.07;
	if (cub3d->map.map[(int)(cub3d->rc.posx)][(int)(cub3d->rc.posy
			- cub3d->rc.diry * 0.07)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx)][
			(int)(cub3d->rc.posy - cub3d->rc.diry * 0.07)]))
		cub3d->rc.posy -= cub3d->rc.diry * 0.07;
}

void	key_a(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posx - cub3d->rc.diry
			* 0.07)][(int)(cub3d->rc.posy)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx - cub3d->rc.diry
				* 0.07)][(int)(cub3d->rc.posy)]))
		cub3d->rc.posx -= cub3d->rc.diry * 0.07;
	if (cub3d->map.map[(int)(cub3d->rc.posx)][(int)(cub3d->rc.posy
			+ cub3d->rc.dirx * 0.07)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx)][
			(int)(cub3d->rc.posy + cub3d->rc.dirx * 0.07)]))
		cub3d->rc.posy += cub3d->rc.dirx * 0.07;
}

void	key_d(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posx + cub3d->rc.diry
			* 0.07)][(int)(cub3d->rc.posy)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx + cub3d->rc.diry
				* 0.07)][(int)(cub3d->rc.posy)]))
		cub3d->rc.posx += cub3d->rc.diry * 0.07;
	if (cub3d->map.map[(int)(cub3d->rc.posx)][(int)(cub3d->rc.posy
			- cub3d->rc.dirx * 0.07)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx)][
			(int)(cub3d->rc.posy - cub3d->rc.dirx * 0.07)]))
		cub3d->rc.posy -= cub3d->rc.dirx * 0.07;
}

void	key_left(t_cub3d *cub3d)
{
	double	value;
	double	old_dirx;
	double	old_planex;

	value = -0.03;
	if (cub3d->map.user_type == 'E' || cub3d->map.user_type == 'W')
		value = 0.03;
	old_dirx = cub3d->rc.dirx;
	cub3d->rc.dirx = cub3d->rc.dirx * cos(value) - cub3d->rc.diry * sin(value);
	cub3d->rc.diry = old_dirx * sin(value) + cub3d->rc.diry * cos(value);
	old_planex = cub3d->rc.planex;
	cub3d->rc.planex = cub3d->rc.planex * cos(value) - cub3d->rc.planey
		* sin(value);
	cub3d->rc.planey = old_planex * sin(value) + cub3d->rc.planey * cos(value);
}
