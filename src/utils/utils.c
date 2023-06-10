/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:01:20 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/10 13:14:19 by yugurlu          ###   ########.fr       */
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
