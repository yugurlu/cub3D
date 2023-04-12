/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:51:01 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/12 12:36:32 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	fill_map(t_cub3d *cub3d)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(cub3d->map_info.map_name, O_RDONLY);
	line = get_next_line(fd);
	if (cub3d->map_info.map_height != -1)
		cub3d->map_info.map = malloc(sizeof(char *)
				* (cub3d->map_info.map_height + 1));
	while (line)
	{
		while (line && is_mapline(line))
		{
			cub3d->map_info.map[i++] = ft_strdup(line);
			free(line);
			line = get_next_line(fd);
		}
		line = get_next_line(fd);
	}
	close(fd);
}
