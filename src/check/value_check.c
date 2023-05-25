/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusufugurlu <yusufugurlu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:51:13 by yugurlu           #+#    #+#             */
/*   Updated: 2023/05/25 11:22:38 by yusufugurlu      ###   ########.fr       */
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
	fd[0] = open(cub3d->map.NO, R_OK);
	printf("%s %d\n", cub3d->map.NO, fd[0]);
	fd[1] = open(cub3d->map.SO, R_OK);
	printf("%s %d\n", cub3d->map.SO, fd[1]);
	fd[2] = open(cub3d->map.WE, R_OK);
	printf("%s %d\n", cub3d->map.WE, fd[2]);
	fd[3] = open(cub3d->map.EA, R_OK);
	printf("%s %d\n", cub3d->map.EA, fd[3]);
	return (fd);
}

int	value_check(t_cub3d *cub3d)
{
	int	*fd;

	fd = open_files(cub3d);
	if ((cub3d->map.NO == NULL || cub3d->map.SO == NULL || cub3d->map.WE == NULL
			|| cub3d->map.EA == NULL) && error(1))
		return (1);
	if ((fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1) && error(2))
		return (1);
	if ((cub3d->map.F[0] == -1 || cub3d->map.F[1] == -1 || cub3d->map.F[1] == -1
			|| cub3d->map.C[0] == -1 || cub3d->map.C[1] == -1
			|| cub3d->map.C[2] == -1) && error(3))
		return (1);
	if ((cub3d->map.F[0] > 255 || cub3d->map.F[1] > 255 || cub3d->map.F[2] > 255
			|| cub3d->map.C[0] > 255 || cub3d->map.C[1] > 255
			|| cub3d->map.C[2] > 255) && error(4))
		return (1);
	if ((cub3d->map.F[0] < 0 || cub3d->map.F[1] < 0 || cub3d->map.F[2] < 0
			|| cub3d->map.C[0] < 0 || cub3d->map.C[1] < 0
			|| cub3d->map.C[2] < 0) && error(5))
		return (1);
	free(fd);
	return (0);
}
