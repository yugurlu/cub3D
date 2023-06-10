/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:16:22 by bsamli            #+#    #+#             */
/*   Updated: 2023/06/07 18:35:44 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_right(t_cub3d *cub3d)
{
	double	value;
	double	old_dirx;
	double	old_planex;

	value = 0.03;
	if (cub3d->map.user_type == 'E' || cub3d->map.user_type == 'W')
		value = -0.03;
	old_dirx = cub3d->rc.dirx;
	cub3d->rc.dirx = cub3d->rc.dirx * cos(value) - cub3d->rc.diry * sin(value);
	cub3d->rc.diry = old_dirx * sin(value) + cub3d->rc.diry * cos(value);
	old_planex = cub3d->rc.planex;
	cub3d->rc.planex = cub3d->rc.planex * cos(value) - cub3d->rc.planey
		* sin(value);
	cub3d->rc.planey = old_planex * sin(value) + cub3d->rc.planey * cos(value);
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
