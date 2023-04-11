/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:54 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/11 18:24:00 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	*map_name;
	int		map_width;
	int		map_height;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	int		error;
}			t_map;

typedef struct s_cub3d
{
	t_map	map_info;
}			t_cub3d;

int			is_mapline(char *line);
int			get_map(t_cub3d *cub3d);
void		free_split(char **split);
void		fill_map(t_cub3d *cub3d);
void		get_height(t_cub3d *cub3d);
int			wall_check(t_cub3d *cub3d);
int			character_check(t_cub3d *cub3d);
int			check(int ac, char **av, t_cub3d *cub3d);
#endif
