/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:54 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/01 19:15:10 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\x1b[31m"

typedef struct s_mlx
{
	void		*mlx_init;
	void		*mlx_window;
	void		*mlx_object;
	int			*mlx_object_data;
	void		*mlx_minimap;
	int			*mlx_minimap_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			minimap_bpp;
	int			minimap_size_line;
	int			minimap_endian;
	void		*mlx_img;
}				t_mlx;

typedef struct s_map
{
	char		**map;
	char		*map_name;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		user_type;
	int			F[3];
	int			C[3];
	int			error;
	int			width;
	int			height;
	long		floor_color;
	long		ceiling_color;
}				t_map;

typedef struct s_assets
{
	int			size;
	void		*NO;
	int			*NO_data;
	int			NO_bpp;
	int			NO_size_line;
	int			NO_endian;
	void		*SO;
	void		*WE;
	void		*EA;
}				t_assets;

typedef struct s_rc
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	double		perpWallDist;
	int			lineHeight;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			wall;
	int			side;
	int			drawStart;
	int			drawEnd;
	int			texX;
	int			texNum;
	double		texStep;
	double		texPos;
	int			user_x;
	int			user_y;
	int			key_w;
	int			key_s;
	int			key_left;
	int			key_right;
	int			key_a;
	int			key_d;
}				t_rc;

typedef struct s_cub3d
{
	t_map		map;
	t_mlx		mlx;
	t_assets	assets;
	t_rc		rc;
}				t_cub3d;

int				error(int type);
void			move(t_cub3d *cub3d);
void			game(t_cub3d *cub3d);
int handleMouseMove(int x, int y, t_cub3d *cub3d);
int				draw(t_cub3d *cub3d);
int				is_mapline(char *line);
int				get_map(t_cub3d *cub3d);
void			free_split(char **split);
void			fill_map(t_cub3d *cub3d);
void			get_height(t_cub3d *cub3d);
int				wall_check(t_cub3d *cub3d);
void			ray_casting(t_cub3d *cub3d);
int				value_check(t_cub3d *cub3d);
int				press(int key, void *cub3d);
int				character_check(t_cub3d *cub3d);
int				release(int key, t_cub3d *cub3d);
void			floor_and_ceiling(t_cub3d *cub3d);
void			rgb_to_hexadecimal(t_cub3d *cub3d);
int				close_window(int key, void *cub3d);
int				check(int ac, char **av, t_cub3d *cub3d);
int				is_character(char c);
#endif
