/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:16:08 by bsamli            #+#    #+#             */
/*   Updated: 2023/06/10 12:51:51 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	texture(t_cub3d *cub3d, int x)
{
	int	texy;

	set_value(cub3d);
	while (cub3d->rc.drawstart < cub3d->rc.drawend)
	{
		texy = (int)cub3d->rc.texpos & 63;
		cub3d->rc.texpos += cub3d->rc.texstep;
		if (cub3d->rc.side == 0 && cub3d->rc.raydirx > 0) // side == 0 -> ışın cisme y ekseninden çarpıyor
			cub3d->mlx.mlx_object_data[cub3d->rc.drawstart * 1920
				+ x] = cub3d->assets.so_data[64 * texy + cub3d->rc.tex_x];
		else if (cub3d->rc.side == 0 && cub3d->rc.raydirx < 0)
			cub3d->mlx.mlx_object_data[cub3d->rc.drawstart * 1920
				+ x] = cub3d->assets.no_data[64 * texy + cub3d->rc.tex_x];
		else if (cub3d->rc.side == 1 && cub3d->rc.raydiry > 0)
			cub3d->mlx.mlx_object_data[cub3d->rc.drawstart * 1920
				+ x] = cub3d->assets.ea_data[64 * texy + cub3d->rc.tex_x];
		else
			cub3d->mlx.mlx_object_data[cub3d->rc.drawstart * 1920
				+ x] = cub3d->assets.we_data[64 * texy + cub3d->rc.tex_x];
		cub3d->rc.drawstart++;
	}
}
