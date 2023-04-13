/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:39:11 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/13 20:59:51 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void game(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_init = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx_init, 1320, 800, "CUB3D");
	cub3d->mlx.mlx_img = mlx_new_image(cub3d->mlx.mlx_init, 1320, 800);
	cub3d->mlx.mlx_data = (int*)mlx_get_data_addr(cub3d->mlx.mlx_img, &cub3d->mlx.bits_per_pixel, &cub3d->mlx.size_line, &cub3d->mlx.endian);
	cub3d->map_info.width = 1320;
	cub3d->map_info.height = 800;
	cub3d->assets.size = 64;
	mlx_loop_hook(cub3d->mlx.mlx_init, &draw, cub3d);
	mlx_loop(cub3d->mlx.mlx_init);
}
