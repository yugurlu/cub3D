/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:39:11 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/01 19:18:50 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	img(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	printf("\n\n%s\n\n", cub3d->map.NO);
	cub3d->assets.NO = mlx_xpm_file_to_image(cub3d->mlx.mlx_init,
			"src/assets/wall1.xpm", &x, &y);
	cub3d->assets.NO_data = (int *)mlx_get_data_addr(cub3d->assets.NO,
			&cub3d->assets.NO_bpp, &cub3d->assets.NO_size_line,
			&cub3d->assets.NO_endian);
}

void	user_location(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	while (cub3d->map.map[x])
	{
		y = 0;
		while (cub3d->map.map[x][y])
		{
			if (cub3d->map.map[x][y] == 'N' || cub3d->map.map[x][y] == 'S'
				|| cub3d->map.map[x][y] == 'W' || cub3d->map.map[x][y] == 'E')
			{
				cub3d->rc.posX = x;
				cub3d->rc.posY = y;
				cub3d->map.user_type = cub3d->map.map[x][y];
				printf("\n\n%c\n\n", cub3d->map.user_type);
				return ;
			}
			y++;
		}
		x++;
	}
}

void	camera(t_cub3d *cub3d)
{
	if (cub3d->map.map[(int)cub3d->rc.posX][(int)cub3d->rc.posY] == 'N')
	{
		cub3d->rc.dirX = -1;
		cub3d->rc.dirY = 0;
		cub3d->rc.planeX = 0;
		cub3d->rc.planeY = -0.66;
	}
	if (cub3d->map.map[(int)cub3d->rc.posX][(int)cub3d->rc.posY] == 'S')
	{
		cub3d->rc.dirX = 1;
		cub3d->rc.dirY = 0;
		cub3d->rc.planeX = 0;
		cub3d->rc.planeY = 0.66;
	}
	if (cub3d->map.map[(int)cub3d->rc.posX][(int)cub3d->rc.posY] == 'W')
	{
		cub3d->rc.dirX = 0;
		cub3d->rc.dirY = -1;
		cub3d->rc.planeX = -0.66;
		cub3d->rc.planeY = 0;
	}
	if (cub3d->map.map[(int)cub3d->rc.posX][(int)cub3d->rc.posY] == 'E')
	{
		cub3d->rc.dirX = 0;
		cub3d->rc.dirY = 1;
		cub3d->rc.planeX = 0.66;
		cub3d->rc.planeY = 0;
	}
}

void	control(t_cub3d *cub3d)
{
	cub3d->rc.key_left = 0;
	cub3d->rc.key_s = 0;
	cub3d->rc.key_right = 0;
	cub3d->rc.key_w = 0;
}

void	set_variables(t_cub3d *cub3d)
{
	img(cub3d);
	user_location(cub3d);
	camera(cub3d);
	control(cub3d);
}

void	game(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_init = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx_init, 1920, 1080,
			"CUB3D");
	cub3d->mlx.mlx_object = mlx_new_image(cub3d->mlx.mlx_init, 1920, 1080);
	cub3d->mlx.mlx_object_data = (int *)mlx_get_data_addr(cub3d->mlx.mlx_object,
			&cub3d->mlx.bits_per_pixel, &cub3d->mlx.size_line,
			&cub3d->mlx.endian);
	cub3d->map.width = 1920;
	cub3d->map.height = 1080;
	set_variables(cub3d);
	mlx_loop_hook(cub3d->mlx.mlx_init, &draw, cub3d);
	mlx_hook(cub3d->mlx.mlx_window, 2, 0, &press, cub3d);
	mlx_hook(cub3d->mlx.mlx_window, 3, 0, &release, cub3d);
	mlx_hook(cub3d->mlx.mlx_window, 17, 1L << 17, &close_window, cub3d);
	mlx_loop(cub3d->mlx.mlx_init);
}
