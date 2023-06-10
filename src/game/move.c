/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:20:32 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/10 11:57:56 by yugurlu          ###   ########.fr       */
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
	if (cub3d->rc.key_a)
		key_a(cub3d);
	if (cub3d->rc.key_d)
		key_d(cub3d);
}
