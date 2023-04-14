/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:41 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/14 17:27:53 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	floor_and_ceiling(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub3d->map_info.width)
	{
		x = -1;
		while (++x < cub3d->map_info.height)
		{
			if (x < cub3d->map_info.height / 2)
				cub3d->mlx.mlx_data[x * cub3d->map_info.width
					+ y] = cub3d->map_info.ceiling_color;
			else
				cub3d->mlx.mlx_data[x * cub3d->map_info.width
					+ y] = cub3d->map_info.floor_color;
		}
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->mlx.mlx_img, 0, 0);
}

void	clouds(t_cub3d *cub3d)
{
	cub3d->assets.cloud = mlx_xpm_file_to_image(cub3d->mlx.mlx_init,
			"src/assets/cloud.xpm", &cub3d->assets.size, &cub3d->assets.size);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cloud, 50, 50);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cloud, 250, 25);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cloud, 450, 50);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cloud, 650, 25);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cloud, 850, 50);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cloud, 1050, 25);
}

void	player_crosshair(t_cub3d *cub3d)
{
	cub3d->assets.character = mlx_xpm_file_to_image(cub3d->mlx.mlx_init,
			"src/assets/character.xpm", &cub3d->assets.size,
			&cub3d->assets.size);
	cub3d->assets.cross = mlx_xpm_file_to_image(cub3d->mlx.mlx_init,
			"src/assets/cross.xpm", &cub3d->assets.size, &cub3d->assets.size);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.character, 775, 475);
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->assets.cross, 650, 375);
}


void mini_map(t_cub3d *cub3d)
{
	int x;
	int y;
	int pixel_y;
	int pixel_x;

	y = -1;
	pixel_y = 2;
	cub3d->mlx.mlx_minimap = mlx_new_image(cub3d->mlx.mlx_init, 160, 75);
	cub3d->mlx.mlx_minimap_data = (int *)mlx_get_data_addr(cub3d->mlx.mlx_minimap, &cub3d->mlx.minimap_bpp, &cub3d->mlx.minimap_size_line, &cub3d->mlx.minimap_endian);
	while (cub3d->map_info.map[++y])
	{
		x = -1;
		pixel_x = 0;
		while (cub3d->map_info.map[y][++x])
		{
			if (cub3d->map_info.map[y][x] == '1')
			{
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x + 1] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x + 2] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x + 3] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x + 1] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x + 2] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x + 3] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x + 1] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x + 2] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x + 3] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 2) * 160 + pixel_x] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 2) * 160 + pixel_x + 1] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 2) * 160 + pixel_x + 2] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 2) * 160 + pixel_x + 3] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 3) * 160 + pixel_x] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 3) * 160 + pixel_x + 1] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 3) * 160 + pixel_x + 2] = 0x00FF00;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 3) * 160 + pixel_x + 3] = 0x00FF00;
			}
			else if(cub3d->map_info.map[y][x] == 'N' || cub3d->map_info.map[y][x] == 'E' || cub3d->map_info.map[y][x] == 'S' || cub3d->map_info.map[y][x] == 'W')
			{
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x + 1] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[pixel_y * 160 + pixel_x + 2] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x + 1] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[(pixel_y + 1) * 160 + pixel_x + 2] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x + 1] = 0xFF0000;
				cub3d->mlx.mlx_minimap_data[(pixel_y - 1) * 160 + pixel_x + 2] = 0xFF0000;
			}
			pixel_x += 4;
		}
		pixel_y += 5;
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window, cub3d->mlx.mlx_minimap, 10, 10);
}

void clear_img(t_cub3d *cub3d)
{
	static int i = 0;

	if (i++ > 0)
	{
		mlx_destroy_image(cub3d->mlx.mlx_init, cub3d->mlx.mlx_minimap);
		mlx_destroy_image(cub3d->mlx.mlx_init, cub3d->assets.character);
		mlx_destroy_image(cub3d->mlx.mlx_init, cub3d->assets.cross);
		mlx_destroy_image(cub3d->mlx.mlx_init, cub3d->assets.cloud);
	}
}

int	draw(t_cub3d *cub3d)
{
	clear_img(cub3d);
	clouds(cub3d);
	player_crosshair(cub3d);
	mini_map(cub3d);
	return (0);
}
