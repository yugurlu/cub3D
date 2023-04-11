/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:01:41 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/11 18:37:58 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void print_data(t_cub3d *cub3d)
{
	int i;

	printf("NO: %s\n", cub3d->map_info.NO);
	printf("SO: %s\n", cub3d->map_info.SO);
	printf("WE: %s\n", cub3d->map_info.WE);
	printf("EA: %s\n", cub3d->map_info.EA);
	printf("F: %d,%d,%d\n", cub3d->map_info.F[0], cub3d->map_info.F[1], cub3d->map_info.F[2]);
	printf("C: %d,%d,%d\n", cub3d->map_info.C[0], cub3d->map_info.C[1], cub3d->map_info.C[2]);
	printf("\n\n");
	i = 0;
	while (cub3d->map_info.map[i])
		printf("%s", cub3d->map_info.map[i++]);

}

int map_control(t_cub3d *cub3d)
{
	get_map(cub3d);
	if(!cub3d->map_info.map)
	{
		printf("Map is not found!\nError\n");
		return (1);
	}
	if(wall_check(cub3d) || character_check(cub3d))
	{
		printf("Wrong formatted map!\nError\n");
		return (1);
	}
	print_data(cub3d);
	return (0);
}

int file_control(char *file, t_cub3d *cub3d)
{
	int i;
	int fd;

	i = 0;
	fd = open(file, R_OK);
	while (file[i])
		i++;
	if (file[i - 1] == 'b' && file[i - 2] == 'u' && file[i - 3] == 'c' && file[i - 4] == '.' && fd != -1)
	{
		cub3d->map_info.map_name = ft_strdup(file);
		return(0);
	}
	else
		printf("Wrong map file!\nError\n");
	return(1);
}

int check(int ac, char **av, t_cub3d *cub3d)
{
	if (ac != 2)
	{
		printf("Wrong number of argument!s\nError\n");
		return (1);
	}
	if (file_control(av[1], cub3d) || map_control(cub3d))
		return (1);
	return (0);

}
