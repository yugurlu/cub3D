/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:01:20 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/01 16:36:24 by bsamli           ###   ########.fr       */
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
	cub3d->map.floor_color = (cub3d->map.F[0] << 16)
		+ (cub3d->map.F[1] << 8) + cub3d->map.F[2];
	cub3d->map.ceiling_color = (cub3d->map.C[0] << 16)
		+ (cub3d->map.C[1] << 8) + cub3d->map.C[2];
}
