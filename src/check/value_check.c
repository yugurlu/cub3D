/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:51:13 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/24 14:49:50 by yugurlu          ###   ########.fr       */
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
		printf("%sMissing RGB value!\nError\n", RED);
	else if (type == 4)
		printf("%sRGB values must be less than 255!\nError\n", RED);
	else
		printf("%sRGB value must be bigger than 0\nError\n", RED);
	return (1);
}

int	*open_files(t_cub3d *cub3d)
{
	int	*fd;

	fd = malloc(12);
	fd[0] = open(cub3d->map_info.NO, R_OK);
	printf("%s\n", cub3d->map_info.NO);
	fd[1] = open(cub3d->map_info.SO, R_OK);
	printf("%s\n", cub3d->map_info.SO);
	fd[2] = open(cub3d->map_info.WE, R_OK);
	printf("%s\n", cub3d->map_info.WE);
	fd[3] = open(cub3d->map_info.EA, R_OK);
	printf("%s\n", cub3d->map_info.EA);
	return (fd);
}

int	value_check(t_cub3d *cub3d)
{
	int	*fd;

	fd = open_files(cub3d);
	if ((cub3d->map_info.NO == NULL || cub3d->map_info.SO == NULL
			|| cub3d->map_info.WE == NULL || cub3d->map_info.EA == NULL)
		&& error(1))
		return (1);
	if ((fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1) && error(2))
		return (1);
	if ((cub3d->map_info.F[0] == -1 || cub3d->map_info.F[1] == -1
			|| cub3d->map_info.F[1] == -1 || cub3d->map_info.C[0] == -1
			|| cub3d->map_info.C[1] == -1 || cub3d->map_info.C[2] == -1)
		&& error(3))
		return (1);
	if ((cub3d->map_info.F[0] > 255 || cub3d->map_info.F[1] > 255
			|| cub3d->map_info.F[2] > 255 || cub3d->map_info.C[0] > 255
			|| cub3d->map_info.C[1] > 255 || cub3d->map_info.C[2] > 255)
		&& error(4))
		return (1);
	if ((cub3d->map_info.F[0] < 0 || cub3d->map_info.F[1] < 0
			|| cub3d->map_info.F[2] < 0 || cub3d->map_info.C[0] < 0
			|| cub3d->map_info.C[1] < 0 || cub3d->map_info.C[2] < 0)
		&& error(5))
		return (1);
	return (0);
}
