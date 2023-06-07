/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:39:11 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/07 18:53:10 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	img(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	printf("\n\n%s\n\n", cub3d->map.no);
	cub3d->assets.no = mlx_xpm_file_to_image(cub3d->mlx.mlx_init,
			"src/assets/assets1.xpm", &x, &y);
	cub3d->assets.no_data = (int *)mlx_get_data_addr(cub3d->assets.no,
			&cub3d->assets.no_bpp, &cub3d->assets.no_size_line,
			&cub3d->assets.no_endian);
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
				cub3d->rc.posx = x;
				cub3d->rc.posy = y;
				cub3d->map.user_type = cub3d->map.map[x][y];
				printf("\n\n%c\n\n", cub3d->map.user_type);
				return ;
			}
			y++;
		}
		x++;
	}
}

void	game(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_init = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx_init, 1920, 1080,
			"CUB3D");
	cub3d->mlx.mlx_object = mlx_new_image(cub3d->mlx.mlx_init, 1920, 1080);
	cub3d->mlx.mlx_object_data = (int *)mlx_get_data_addr(cub3d->mlx.mlx_object,
			&cub3d->mlx.bits_per_pixel,
			&cub3d->mlx.size_line,
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
