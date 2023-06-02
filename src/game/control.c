/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:42:25 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/01 16:14:22 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	close_window(int key, void *cub3d)
{
	(void)key;
	(void)cub3d;
	exit(0);
}

int	press(int key, void *cub3dd)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)cub3dd;
	if (key == 13)
		cub3d->rc.key_w = 1;
	if (key == 1)
		cub3d->rc.key_s = 1;
	if (key == 123)
		cub3d->rc.key_left = 1;
	if (key == 124)
		cub3d->rc.key_right = 1;
	if (key == 0)
		cub3d->rc.key_a = 1;
	if (key == 2)
		cub3d->rc.key_d = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int	release(int key, t_cub3d *cub3d)
{
	if (key == 13)
		cub3d->rc.key_w = 0;
	if (key == 1)
		cub3d->rc.key_s = 0;
	if (key == 123)
		cub3d->rc.key_left = 0;
	if (key == 124)
		cub3d->rc.key_right = 0;
	if (key == 0)
		cub3d->rc.key_a = 0;
	if (key == 2)
		cub3d->rc.key_d = 0;
	return (0);
}
