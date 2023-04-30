/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:51:01 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/30 17:53:54 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_strncopy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	fill_map(t_cub3d *cub3d)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(cub3d->map.map_name, O_RDONLY);
	line = get_next_line(fd);
	if (cub3d->map.height == -1)
	{
		cub3d->map.map = NULL;
		return ;
	}
	cub3d->map.map = malloc(sizeof(char *) * (cub3d->map.height + 1));
	while (line)
	{
		while (line && is_mapline(line))
		{
			cub3d->map.map[i] = malloc(ft_strlen(line) + 1);
			ft_strncopy(cub3d->map.map[i++], line, ft_strlen(line) - 1);
			free(line);
			line = get_next_line(fd);
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	cub3d->map.map[i] = NULL;
	close(fd);
}
