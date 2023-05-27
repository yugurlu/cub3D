/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusufugurlu <yusufugurlu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:02:58 by yugurlu           #+#    #+#             */
/*   Updated: 2023/05/27 11:36:12 by yusufugurlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	direction(t_cub3d *cub3d)
{
	if (cub3d->rc.rayDirX < 0)
	{
		cub3d->rc.stepX = -1;
		cub3d->rc.sideDistX = (cub3d->rc.posX - cub3d->rc.mapX)
			* cub3d->rc.deltaDistX;
	}
	else
	{
		cub3d->rc.stepX = 1;
		cub3d->rc.sideDistX = (cub3d->rc.mapX + 1.0 - cub3d->rc.posX)
			* cub3d->rc.deltaDistX;
	}
	if (cub3d->rc.rayDirY < 0)
	{
		cub3d->rc.stepY = -1;
		cub3d->rc.sideDistY = (cub3d->rc.posY - cub3d->rc.mapY)
			* cub3d->rc.deltaDistY;
	}
	else
	{
		cub3d->rc.stepY = 1;
		cub3d->rc.sideDistY = (cub3d->rc.mapY + 1.0 - cub3d->rc.posY)
			* cub3d->rc.deltaDistY;
	}
}

void	wallHit(t_cub3d *cub3d) //dda algorithm
{
	cub3d->rc.wall = 0;
	while (!cub3d->rc.wall)
	{
		if (cub3d->rc.sideDistX < cub3d->rc.sideDistY)
		{
			cub3d->rc.sideDistX += cub3d->rc.deltaDistX;
			cub3d->rc.mapX += cub3d->rc.stepX;
			cub3d->rc.side = 0;
		}
		else
		{
			cub3d->rc.sideDistY += cub3d->rc.deltaDistY;
			cub3d->rc.mapY += cub3d->rc.stepY;
			cub3d->rc.side = 1;
		}
		if (cub3d->map.map[cub3d->rc.mapX][cub3d->rc.mapY] == '1')
			cub3d->rc.wall = 1;
	}
}

void	rayDist(t_cub3d *cub3d)
{
	if (cub3d->rc.side == 0)
		cub3d->rc.perpWallDist = cub3d->rc.sideDistX
			- cub3d->rc.deltaDistX;
	else
		cub3d->rc.perpWallDist = cub3d->rc.sideDistY
			- cub3d->rc.deltaDistY;
	cub3d->rc.lineHeight = (int)(1080 / cub3d->rc.perpWallDist);
	cub3d->rc.drawStart = -cub3d->rc.lineHeight / 2 + 1080 / 2;
	if (cub3d->rc.drawStart < 0)
		cub3d->rc.drawStart = 0;
	cub3d->rc.drawEnd = cub3d->rc.lineHeight / 2 + 1080 / 2;
	if (cub3d->rc.drawEnd >= 1080)
		cub3d->rc.drawEnd = 1080 - 1;
}

void set_value(t_cub3d *cub3d)
{
	double wallX;
	cub3d->rc.texNum = cub3d->map.map[cub3d->rc.mapX][cub3d->rc.mapY] - 1;
	if(cub3d->rc.side == 0)
		wallX = cub3d->rc.posY + cub3d->rc.perpWallDist * cub3d->rc.rayDirY;
	else
		wallX = cub3d->rc.posX + cub3d->rc.perpWallDist * cub3d->rc.rayDirX;
	wallX -= floor(wallX);
	cub3d->rc.texX = (int)(wallX * (double)64);
	if(cub3d->rc.side == 0 && cub3d->rc.rayDirX > 0)
		cub3d->rc.texX = 64 - cub3d->rc.texX - 1;
	if(cub3d->rc.side == 1 && cub3d->rc.rayDirY < 0)
		cub3d->rc.texX = 64 - cub3d->rc.texX - 1;
	cub3d->rc.texStep = 1.0 * 64 / cub3d->rc.lineHeight;
	cub3d->rc.texPos = (cub3d->rc.drawStart - 1080 / 2 + cub3d->rc.lineHeight / 2) * cub3d->rc.texStep;
}

void	texture(t_cub3d *cub3d, int x)
{
	//int texY;
	int	start;

	//set_value(cub3d);
	start = cub3d->rc.drawStart;
	while (start < cub3d->rc.drawEnd)
	{
		//texY = (int)cub3d->rc.texPos & 63;
		cub3d->rc.texPos += cub3d->rc.texStep;
		//cub3d->mlx.mlx_object_data[start * 1920 + x] = cub3d->assets.NO_data[64 * texY + cub3d->rc.texX];
		if(cub3d->rc.side == 0 && cub3d->rc.rayDirX > 0) // side == 0 -> ışın cisme y ekseninden çarpıyor
			cub3d->mlx.mlx_object_data[start * 1920 + x] = 0xFF0000;
		else if(cub3d->rc.side == 0 && cub3d->rc.rayDirX < 0)
			cub3d->mlx.mlx_object_data[start * 1920 + x] = 0x0000FF;
		else if(cub3d->rc.side == 1 && cub3d->rc.rayDirY > 0)
			cub3d->mlx.mlx_object_data[start * 1920 + x] = 0xFF00FF;
		else
			cub3d->mlx.mlx_object_data[start* 1920 + x] = 0x00FF00;
		start++;
	}
}

void	ray_casting(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < 1920)
	{
		cub3d->rc.cameraX = 2 * x / (double)1920 - 1; //kamera sadece x ekseninde yön değiştireceği için sadece x konumu hesaplanıyor
		cub3d->rc.rayDirX = cub3d->rc.dirX + cub3d->rc.planeX * cub3d->rc.cameraX; // yön vektörleri
		cub3d->rc.rayDirY = cub3d->rc.dirY + cub3d->rc.planeY * cub3d->rc.cameraX;
		cub3d->rc.mapX = (int)cub3d->rc.posX; // map konumu
		cub3d->rc.mapY = (int)cub3d->rc.posY;
		cub3d->rc.deltaDistX = fabs(1 / cub3d->rc.rayDirX); // bir sonraki üçgenin x veya y eksenindeki duvara ulaşabilmek için gerekli mesafe
		cub3d->rc.deltaDistY = fabs(1 / cub3d->rc.rayDirY);
		direction(cub3d); // dda için x ve y eksenlerinde izlenicek adım hesaplaması
		wallHit(cub3d); // dda ile, cisme gönderilen ışının hangi eksende cisme çarptığı
		rayDist(cub3d); // çizilicek duvarın boyu ve kamera ve cisim arasındaki mesafe
		texture(cub3d, x); // duvarın taraflarına göre texture basımı
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx.mlx_init, cub3d->mlx.mlx_window,
			cub3d->mlx.mlx_object, 0, 0);
}
