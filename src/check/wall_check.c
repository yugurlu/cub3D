/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:05:35 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/30 17:54:57 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	wall_check(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map.map[i])
	{
		j = 0;
		while (cub3d->map.map[i][j])
		{
			if (cub3d->map.map[i][j] == '0')
			{
				if (!((cub3d->map.map[i][j + 1] == '0'
							|| cub3d->map.map[i][j + 1] == '1'
							|| cub3d->map.map[i][j + 1] == 'N'
							|| cub3d->map.map[i][j + 1] == 'S'
							|| cub3d->map.map[i][j + 1] == 'E'
							|| cub3d->map.map[i][j + 1] == 'W'
							|| cub3d->map.map[i][j + 1] == ' ')
						&& (cub3d->map.map[i][j - 1] == '0'
							|| cub3d->map.map[i][j - 1] == '1'
							|| cub3d->map.map[i][j - 1] == 'N'
							|| cub3d->map.map[i][j - 1] == 'S'
							|| cub3d->map.map[i][j - 1] == 'E'
							|| cub3d->map.map[i][j - 1] == 'W'
							|| cub3d->map.map[i][j - 1] == ' ')
						&& (cub3d->map.map[i + 1][j] == '0'
							|| cub3d->map.map[i + 1][j] == '1'
							|| cub3d->map.map[i + 1][j] == 'N'
							|| cub3d->map.map[i + 1][j] == 'S'
							|| cub3d->map.map[i + 1][j] == 'E'
							|| cub3d->map.map[i + 1][j] == 'W'
							|| cub3d->map.map[i + 1][j] == ' ')
						&& (cub3d->map.map[i - 1][j] == '0'
							|| cub3d->map.map[i - 1][j] == '1'
							|| cub3d->map.map[i - 1][j] == 'N'
							|| cub3d->map.map[i - 1][j] == 'S'
							|| cub3d->map.map[i - 1][j] == 'E'
							|| cub3d->map.map[i - 1][j] == 'W'
							|| cub3d->map.map[i - 1][j] == ' ')))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
