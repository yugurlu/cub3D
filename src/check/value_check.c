/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:51:13 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/14 14:39:55 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	error(int type)
{
	if (type == 1)
		printf("%sMissing image information!\nError\n", RED);
	else if (type == 2)
		printf("%sImage file not found!\nError\n", RED);
	else if (type == 3)
		printf("%sWrong RGB value!\nError\n", RED);
	else if (type == 4)
		printf("%sRGB values must be less than 255!\nError\n", RED);
	else if (type == 5)
		printf("%sRGB value must be bigger than 0\nError\n", RED);
	else if (type == 6)
		printf("%sMap is not found!\nError\n", RED);
	else if (type == 7)
		printf("%sWrong formatted map!\nError\n", RED);
	else if (type == 8)
		printf("%sWrong map file!\nError\n", RED);
	else if (type == 9)
		printf("%sWrong number of argument!s\nError\n", RED);
	return (1);
}

int	*open_files(t_cub3d *cub3d)
{
	int	*fd;

	fd = malloc(16);
	fd[0] = open(cub3d->map.no, R_OK);
	fd[1] = open(cub3d->map.so, R_OK);
	fd[2] = open(cub3d->map.we, R_OK);
	fd[3] = open(cub3d->map.ea, R_OK);
	return (fd);
}

int	value_check(t_cub3d *cub3d)
{
	int	*fd;

	fd = open_files(cub3d);
	if ((cub3d->map.no == NULL || cub3d->map.so == NULL || cub3d->map.we == NULL
			|| cub3d->map.ea == NULL) && error(1) && my_free(fd))
		return (1);
	if ((fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1) && error(2)
		&& my_free(fd))
		return (1);
	if ((cub3d->map.f[0] == -1 || cub3d->map.f[1] == -1 || cub3d->map.f[1] == -1
			|| cub3d->map.c[0] == -1 || cub3d->map.c[1] == -1
			|| cub3d->map.c[2] == -1) && error(3) && my_free(fd))
		return (1);
	if ((cub3d->map.f[0] > 255 || cub3d->map.f[1] > 255 || cub3d->map.f[2] > 255
			|| cub3d->map.c[0] > 255 || cub3d->map.c[1] > 255
			|| cub3d->map.c[2] > 255) && error(4) && my_free(fd))
		return (1);
	if ((cub3d->map.f[0] < 0 || cub3d->map.f[1] < 0 || cub3d->map.f[2] < 0
			|| cub3d->map.c[0] < 0 || cub3d->map.c[1] < 0
			|| cub3d->map.c[2] < 0) && error(5) && my_free(fd))
		return (1);
	if (cub3d->map.error == 1 && error(3) && my_free(fd))
		return (1);
	free(fd);
	return (0);
}
