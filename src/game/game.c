/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:39:11 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/27 13:14:14 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void img(t_cub3d *cub3d)
{
	int x = 64;
	int y = 64;
	printf("\n\n%s\n\n", cub3d->map_info.NO);
	cub3d->assets.NO = mlx_xpm_file_to_image(cub3d->mlx.mlx_init, "src/assets/wall1.xpm", &x, &y);
	cub3d->assets.NO_data = (int *)mlx_get_data_addr(cub3d->assets.NO, &cub3d->assets.NO_bpp, &cub3d->assets.NO_size_line, &cub3d->assets.NO_endian);
}

void user_location(t_cub3d *cub3d)
{
	int x;
	int y;

	x = 0;
	while(cub3d->map_info.map[x])
	{
		y = 0;
		while (cub3d->map_info.map[x][y])
		{
			if(cub3d->map_info.map[x][y] == 'N' || cub3d->map_info.map[x][y] == 'S' || cub3d->map_info.map[x][y] == 'W' || cub3d->map_info.map[x][y] == 'E')
			{
				cub3d->game.posX = x;
				cub3d->game.posY = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void camera(t_cub3d *cub3d)
{
	if (cub3d->map_info.map[(int)cub3d->game.posX][(int)cub3d->game.posY] == 'N')
	{
		cub3d->game.dirX = -1;
		cub3d->game.dirY = 0;
		cub3d->game.planeX = 0;
		cub3d->game.planeY = -0.66;
	}
	if (cub3d->map_info.map[(int)cub3d->game.posX][(int)cub3d->game.posY] == 'S')
	{
		cub3d->game.dirX = 1;
		cub3d->game.dirY = 0;
		cub3d->game.planeX = 0;
		cub3d->game.planeY = 0.66;
	}
	if (cub3d->map_info.map[(int)cub3d->game.posX][(int)cub3d->game.posY] == 'W')
	{
		cub3d->game.dirX = 0;
		cub3d->game.dirY = -1;
		cub3d->game.planeX = -0.66;
		cub3d->game.planeY = 0;
	}
	if (cub3d->map_info.map[(int)cub3d->game.posX][(int)cub3d->game.posY] == 'E')
	{
		cub3d->game.dirX = 0;
		cub3d->game.dirY = 1;
		cub3d->game.planeX = 0.66;
		cub3d->game.planeY = 0;
	}
}

void	set_variables(t_cub3d *cub3d)
{
	img(cub3d);
	user_location(cub3d);
	camera(cub3d);
}

void game(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_init = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx_init, 1920, 1080, "CUB3D");
	cub3d->mlx.mlx_object = mlx_new_image(cub3d->mlx.mlx_init, 1920, 1080);
	cub3d->mlx.mlx_object_data = (int*)mlx_get_data_addr(cub3d->mlx.mlx_object, &cub3d->mlx.bits_per_pixel, &cub3d->mlx.size_line, &cub3d->mlx.endian);
	cub3d->map_info.width = 1920;
	cub3d->map_info.height = 1080;
	cub3d->assets.size = 64;
	set_variables(cub3d);
	mlx_loop_hook(cub3d->mlx.mlx_init, &draw, cub3d);
	mlx_hook(cub3d->mlx.mlx_window, 2, 1L << 0 ,&press, cub3d);
	mlx_hook(cub3d->mlx.mlx_window, 3, 0L,&release, cub3d);
	mlx_hook(cub3d->mlx.mlx_window, 17, 1L << 17, &close_window, cub3d);
	mlx_loop(cub3d->mlx.mlx_init);
}
