/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:51:21 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/01 16:23:02 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initialize_variables(t_cub3d *cub3d)
{
	cub3d->map.NO = NULL;
	cub3d->map.SO = NULL;
	cub3d->map.WE = NULL;
	cub3d->map.EA = NULL;
	cub3d->map.map = NULL;
	cub3d->map.F[0] = -1;
	cub3d->map.F[1] = -1;
	cub3d->map.F[2] = -1;
	cub3d->map.C[0] = -1;
	cub3d->map.C[1] = -1;
	cub3d->map.C[2] = -1;
	cub3d->map.floor_color = -1;
	cub3d->map.ceiling_color = -1;
	cub3d->map.height = -1;
}

void	get_rgb(char **line, t_cub3d *cub3d)
{
	char	**splited_line;
	int		i;

	i = 0;
	splited_line = ft_split(line[1], ',');
	while (splited_line[i])
		i++;
	if (i == 3 && line[0][0] == 'F')
	{
		cub3d->map.F[0] = ft_atoi(splited_line[0]);
		cub3d->map.F[1] = ft_atoi(splited_line[1]);
		cub3d->map.F[2] = ft_atoi(splited_line[2]);
		rgb_to_hexadecimal(cub3d);
	}
	else if (i == 3 && line[0][0] == 'C')
	{
		cub3d->map.C[0] = ft_atoi(splited_line[0]);
		cub3d->map.C[1] = ft_atoi(splited_line[1]);
		cub3d->map.C[2] = ft_atoi(splited_line[2]);
		rgb_to_hexadecimal(cub3d);
	}
	else
		cub3d->map.error = 1;
	free_split(splited_line);
}

void	parse_line(char *line, t_cub3d *cub3d)
{
	char	**splited_line;
	char	**back_slash_n;
	int		i;

	splited_line = ft_split(line, ' ');
	i = 0;
	while (splited_line[i] != NULL)
		i++;
	if (i == 2)
	{
		back_slash_n = ft_split(splited_line[1], '\n');
		if (ft_strncmp(splited_line[0], "NO", 2) == 0)
			cub3d->map.NO = ft_strdup(back_slash_n[0]);
		else if (ft_strncmp(splited_line[0], "SO", 2) == 0)
			cub3d->map.SO = ft_strdup(back_slash_n[0]);
		else if (ft_strncmp(splited_line[0], "WE", 2) == 0)
			cub3d->map.WE = ft_strdup(back_slash_n[0]);
		else if (ft_strncmp(splited_line[0], "EA", 2) == 0)
			cub3d->map.EA = ft_strdup(back_slash_n[0]);
		else if (ft_strncmp(splited_line[0], "F", 1)
				|| ft_strncmp(back_slash_n[0], "C", 1))
			get_rgb(splited_line, cub3d);
		free_split(back_slash_n);
	}
	free_split(splited_line);
}

int	get_map(t_cub3d *cub3d)
{
	int		fd;
	char	*line;

	initialize_variables(cub3d);
	fd = open(cub3d->map.map_name, O_RDONLY);
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
