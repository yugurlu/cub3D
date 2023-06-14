/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:48:44 by bsamli            #+#    #+#             */
/*   Updated: 2023/06/14 13:07:13 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_d1(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)(cub3d->rc.posx + cub3d->rc.diry
			* 0.07)][(int)(cub3d->rc.posy)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx + cub3d->rc.diry
				* 0.07)][(int)(cub3d->rc.posy)]))
		cub3d->rc.posx += cub3d->rc.diry * 0.07;
	if (cub3d->map.map[(int)(cub3d->rc.posx)][(int)(cub3d->rc.posy
			- cub3d->rc.dirx * 0.07)] == '0'
		|| is_character(cub3d->map.map[(int)(cub3d->rc.posx)]
		[(int)(cub3d->rc.posy - cub3d->rc.dirx * 0.07)]))
		cub3d->rc.posy -= cub3d->rc.dirx * 0.07;
}

void	key_a1(t_cub3d *cub3d)
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
