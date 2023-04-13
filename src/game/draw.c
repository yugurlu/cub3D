/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:41 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/13 21:39:31 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void floor_and_ceiling(t_cub3d *cub3d)
{
	int x;
	int y;

	y = -1;
	while (++y < cub3d->map_info.width)
	{
		x = -1;
		while (++x < cub3d->map_info.height)
		{
			if (x < cub3d->map_info.height / 2)
				cub3d->mlx.mlx_data[x * cub3d->map_info.width + y] = cub3d->map_info.ceiling_color;
			else
				cub3d->mlx.mlx_data[x * cub3d->map_info.width + y] = cub3d->map_info.floor_color;
		}
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->mlx.mlx_img, 0, 0);
}

void clouds(t_cub3d *cub3d)
{
	cub3d->assets.cloud = mlx_xpm_file_to_image(cub3d->mlx.mlx_init, "src/assets/cloud.xpm", &cub3d->assets.size, &cub3d->assets.size);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cloud, 50, 50);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cloud, 250, 25);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cloud, 450, 50);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cloud, 650, 25);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cloud, 850, 50);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cloud, 1050, 25);

}

void player_crosshair(t_cub3d *cub3d)
{
	cub3d->assets.character = mlx_xpm_file_to_image(cub3d->mlx.mlx_init, "src/assets/character.xpm", &cub3d->assets.size, &cub3d->assets.size);
	cub3d->assets.cross = mlx_xpm_file_to_image(cub3d->mlx.mlx_init, "src/assets/cross.xpm", &cub3d->assets.size, &cub3d->assets.size);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.character, 775, 475);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->assets.cross, 650, 375);
}


int draw(t_cub3d *cub3d)
{
	floor_and_ceiling(cub3d);
	clouds(cub3d);
	player_crosshair(cub3d);
	return (0);
}
