/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:30 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/20 16:38:01 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (check(ac, av, cub3d))
		return (0);
	game(cub3d);
}
