/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:01:20 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/13 12:46:02 by yugurlu          ###   ########.fr       */
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
	cub3d->map_info.floor_color = (cub3d->map_info.F[0] << 16)
		+ (cub3d->map_info.F[1] << 8) + cub3d->map_info.F[2];
	cub3d->map_info.ceiling_color = (cub3d->map_info.C[0] << 16)
		+ (cub3d->map_info.C[1] << 8) + cub3d->map_info.C[2];
}
