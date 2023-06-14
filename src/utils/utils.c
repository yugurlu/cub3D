/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:01:20 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/14 14:30:02 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	rgb_control(t_cub3d *cub3d, char *value1, char *value2, char *value3)
{
	int	i;

	i = 0;
	while (value1 && value1[i])
	{
		if (!(48 <= value1[i] && value1[i] <= 57) && value1[i] != '\n')
			cub3d->map.error = 1;
		i++;
	}
	i = 0;
	while (value2 && value2[i])
	{
		if (!(48 <= value2[i] && value2[i] <= 57) && value2[i] != '\n')
			cub3d->map.error = 1;
		i++;
	}
	i = 0;
	while (value3 && value3[i])
	{
		if (!(48 <= value3[i] && value3[i] <= 57) && value3[i] != '\n')
			cub3d->map.error = 1;
		i++;
	}
}

void	rgb_to_hexadecimal(t_cub3d *cub3d)
{
	cub3d->map.floor_color = (cub3d->map.f[0] << 16) + (cub3d->map.f[1] << 8)
		+ cub3d->map.f[2];
	cub3d->map.ceiling_color = (cub3d->map.c[0] << 16) + (cub3d->map.c[1] << 8)
		+ cub3d->map.c[2];
}

int	my_free(int *fd)
{
	free(fd);
	return (1);
}
