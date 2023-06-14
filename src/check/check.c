/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:01:41 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/14 13:59:29 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_data(t_cub3d *cub3d)
{
	int	i;

	printf("NO: %s\n", cub3d->map.no);
	printf("SO: %s\n", cub3d->map.so);
	printf("WE: %s\n", cub3d->map.we);
	printf("EA: %s\n", cub3d->map.ea);
	printf("F: %d,%d,%d\n", cub3d->map.f[0], cub3d->map.f[1], cub3d->map.f[2]);
	printf("C: %d,%d,%d\n", cub3d->map.c[0], cub3d->map.c[1], cub3d->map.c[2]);
	printf("\n\n");
	i = 0;
	while (cub3d->map.map[i])
		printf("%s\n", cub3d->map.map[i++]);
}

int	map_check(t_cub3d *cub3d)
{
	get_map(cub3d);
	if (!cub3d->map.map && error(6))
		return (1);
	print_data(cub3d);
	if ((line_check(cub3d) || character_check(cub3d) || wall_check(cub3d))
		&& error(7))
		return (1);
	return (0);
}

int	file_check(char *file, t_cub3d *cub3d)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, R_OK);
	while (file[i])
		i++;
	if (file[i - 1] == 'b' && file[i - 2] == 'u' && file[i - 3] == 'c' && file[i
			- 4] == '.' && fd != -1)
	{
		cub3d->map.map_name = ft_strdup(file);
		close(fd);
		return (0);
	}
	error(8);
	close(fd);
	return (1);
}

int	check(int ac, char **av, t_cub3d *cub3d)
{
	if (ac != 2 && error(9))
		return (1);
	if (file_check(av[1], cub3d) || map_check(cub3d) || value_check(cub3d))
		return (1);
	return (0);
}
