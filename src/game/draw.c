/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:41 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/27 13:12:07 by yugurlu          ###   ########.fr       */
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
				cub3d->mlx.mlx_object_data[x * cub3d->map_info.width
					+ y] = cub3d->map_info.ceiling_color;
			else
				cub3d->mlx.mlx_object_data[x * cub3d->map_info.width
					+ y] = cub3d->map_info.floor_color;
		}
	}
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
	mlx_destroy_image(cub3d->mlx.mlx_init, cub3d->mlx.mlx_object);
	cub3d->mlx.mlx_object = mlx_new_image(cub3d->mlx.mlx_init, 1920, 1080);
	cub3d->mlx.mlx_object_data = (int *)mlx_get_data_addr(cub3d->mlx.mlx_object, &cub3d->mlx.bits_per_pixel, &cub3d->mlx.size_line, &cub3d->mlx.endian);
}

void move(t_cub3d *cub3d)
{
	double oldDirX;
	double oldPlaneX;
	if(cub3d->game.key_w)
	{
		if(cub3d->map_info.map[(int)(cub3d->game.posX + cub3d->game.dirX * 0.2)][(int)(cub3d->game.posY)] == '0')
			cub3d->game.posX += cub3d->game.dirX * 0.2;
		if(cub3d->map_info.map[(int)cub3d->game.posX][(int)(cub3d->game.posY + cub3d->game.dirY * 0.2)] == '0')
			cub3d->game.posY += cub3d->game.dirY * 0.2;
	}
	if(cub3d->game.key_s)
	{
		if(cub3d->map_info.map[(int)(cub3d->game.posX - cub3d->game.dirX * 0.2)][(int)(cub3d->game.posY)] == '0')
			cub3d->game.posX -= cub3d->game.dirX * 0.2;
		if(cub3d->map_info.map[(int)(cub3d->game.posX)][(int)(cub3d->game.posY - cub3d->game.dirY * 0.2)] == '0')
			cub3d->game.posY -= cub3d->game.dirY * 0.2;
	}
	if (cub3d->game.key_a)
	{
		oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(-0.1) - cub3d->game.dirY * sin(-0.1);
		cub3d->game.dirY = oldDirX * sin(-0.1) + cub3d->game.dirY * cos(-0.1);
		double oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(-0.1) - cub3d->game.planeY * sin(-0.1);
		cub3d->game.planeY = oldPlaneX * sin(-0.1) + cub3d->game.planeY * cos(-0.1);
	}
	if (cub3d->game.key_d)
	{
		oldDirX = cub3d->game.dirX;
		cub3d->game.dirX = cub3d->game.dirX * cos(0.1) - cub3d->game.dirY * sin(0.1);
		cub3d->game.dirY = oldDirX * sin(0.1) + cub3d->game.dirY * cos(0.1);
		oldPlaneX = cub3d->game.planeX;
		cub3d->game.planeX = cub3d->game.planeX * cos(0.1) - cub3d->game.planeY * sin(0.1);
		cub3d->game.planeY = oldPlaneX * sin(0.1) + cub3d->game.planeY * cos(0.1);
	}
}


int	draw(t_cub3d *cub3d)
{
	clear_img(cub3d);
	floor_and_ceiling(cub3d);
	ray_casting(cub3d);
	move(cub3d);
	return (0);
}
