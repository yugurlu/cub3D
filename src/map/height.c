/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:18:40 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/30 15:47:01 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	file_path(char *line, int i)
{
	if (line[i] == '.' && line[i + 1] == '/')
		return (0);
	return (1);
}

int	rgb(char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	if (line[i + 1] == ',' && ft_isdigit(line[i + 2]))
		return (0);
	return (1);
}

int	is_mapline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]) && file_path(line, i) && rgb(line, i))
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

void	get_height(t_cub3d *cub3d)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(cub3d->map.map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (is_mapline(line))
		{
			while (line && is_mapline(line))
			{
				height++;
				free(line);
				line = get_next_line(fd);
			}
			cub3d->map.height = height;
			close(fd);
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
