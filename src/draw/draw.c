/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:39:11 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/12 22:35:21 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void initialize_window(t_cub3d *cub3d)
{
	cub3d->mlx.mlx_init = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx_init, 1320, 800, "CUB3D");
	mlx_loop(cub3d->mlx.mlx_init);
}

void draw(t_cub3d *cub3d)
{
	decimalToHexadecimal(255);
	//initialize_window(cub3d);
}
