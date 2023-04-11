/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:51:21 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/11 15:45:56 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void initialize_variables(t_cub3d *cub3d)
{
	cub3d->map_info.NO = NULL;
	cub3d->map_info.SO = NULL;
	cub3d->map_info.WE = NULL;
	cub3d->map_info.EA = NULL;
	cub3d->map_info.map = NULL;
	cub3d->map_info.F[0] = -1;
	cub3d->map_info.F[1] = -1;
	cub3d->map_info.F[2] = -1;
	cub3d->map_info.C[0] = -1;
	cub3d->map_info.C[1] = -1;
	cub3d->map_info.C[2] = -1;
	cub3d->map_info.map_height = -1;
}

void get_rgb(char **line, t_cub3d *cub3d)
{
	char **splited_line;
	int i;

	i = 0;
	splited_line = ft_split(line[1], ',');
	while (splited_line[i])
		i++;
	if (i == 3 && line[0][0] == 'F')
	{
		cub3d->map_info.F[0] = ft_atoi(splited_line[0]);
		cub3d->map_info.F[1] = ft_atoi(splited_line[1]);
		cub3d->map_info.F[2] = ft_atoi(splited_line[2]);
	}
	else if (i == 3 && line[0][0] == 'C')
	{
		cub3d->map_info.C[0] = ft_atoi(splited_line[0]);
		cub3d->map_info.C[1] = ft_atoi(splited_line[1]);
		cub3d->map_info.C[2] = ft_atoi(splited_line[2]);
	}
	else
		cub3d->map_info.error = 1;
	free_split(splited_line);
}

void parse_line(char *line, t_cub3d *cub3d)
{
	char **splited_line;

	splited_line = ft_split(line, ' ');
	if (splited_line && splited_line[0] && splited_line[1] && !splited_line[2])
	{
		if (ft_strncmp(splited_line[0], "NO", 2) == 0)
			cub3d->map_info.NO = ft_strdup(splited_line[1]);
		else if (ft_strncmp(splited_line[0], "SO", 2) == 0)
			cub3d->map_info.SO = ft_strdup(splited_line[1]);
		else if (ft_strncmp(splited_line[0], "WE", 2) == 0)
			cub3d->map_info.WE = ft_strdup(splited_line[1]);
		else if (ft_strncmp(splited_line[0], "EA", 2) == 0)
			cub3d->map_info.EA = ft_strdup(splited_line[1]);
		else if (ft_strncmp(splited_line[0], "F", 1) || ft_strncmp(splited_line[0], "C", 1))
			get_rgb(splited_line, cub3d);
	}
}

int get_map(t_cub3d *cub3d)
{
	int fd;
	char *line;

	initialize_variables(cub3d);
	fd = open(cub3d->map_info.map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, cub3d);
		free(line);
		line = get_next_line(fd);
	}
	get_height(cub3d);
	fill_map(cub3d);
	close(fd);
	return (0);
}
