/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:54 by yugurlu           #+#    #+#             */
/*   Updated: 2023/06/12 12:32:24 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
	char		*ea;
	char		*so;
	char		*we;
	char		*no;
	char		user_type;
	int			f[3];
	int			c[3];
	int			error;
	int			width;
	int			height;
	long		floor_color;
	long		ceiling_color;
}				t_map;

typedef struct s_assets
{
	int			size;
	void		*no;
	int			*no_data;
	int			no_bpp;
	int			no_size_line;
	int			no_endian;

	int			*so_data;
	int			so_bpp;
	int			so_size_line;
	int			so_endian;

	int			*we_data;
	int			we_bpp;
	int			we_size_line;
	int			we_endian;

	int			*ea_data;
	int			ea_bpp;
	int			ea_size_line;
	int			ea_endian;

	void		*so;
	void		*we;
	void		*ea;
}				t_assets;

typedef struct s_rc
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	int			lineheight;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			wall;
	int			side;
	int			drawstart;
	int			drawend;
	int			tex_x;
	int			texnum;
	double		texstep;
	double		texpos;
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
int				my_free(int *fd);
void			img(t_cub3d *cub3d);
void			move(t_cub3d *cub3d);
int				is_character(char c);
void			game(t_cub3d *cub3d);
int				draw(t_cub3d *cub3d);
void			key_w(t_cub3d *cub3d);
void			key_s(t_cub3d *cub3d);
void			key_a(t_cub3d *cub3d);
void			key_d(t_cub3d *cub3d);
void			camera(t_cub3d *cub3d);
int				is_mapline(char *line);
void			control(t_cub3d *cub3d);
int				get_map(t_cub3d *cub3d);
void			raydist(t_cub3d *cub3d);
void			wallhit(t_cub3d *cub3d);
void			free_split(char **split);
void			key_left(t_cub3d *cub3d);
void			fill_map(t_cub3d *cub3d);
void			key_right(t_cub3d *cub3d);
void			set_value(t_cub3d *cub3d);
void			direction(t_cub3d *cub3d);
int				line_check(t_cub3d *cub3d);
int				wall_check(t_cub3d *cub3d);
void			ray_casting(t_cub3d *cub3d);
int				value_check(t_cub3d *cub3d);
int				press(int key, void *cub3d);
void			set_variables(t_cub3d *cub3d);
void			user_location(t_cub3d *cub3d);
void			texture(t_cub3d *cub3d, int x);
int				character_check(t_cub3d *cub3d);
int				release(int key, t_cub3d *cub3d);
void			floor_and_ceiling(t_cub3d *cub3d);
void			rgb_to_hexadecimal(t_cub3d *cub3d);
int				close_window(int key, void *cub3d);
void			get_height(t_cub3d *cub3d, int height);
int				check(int ac, char **av, t_cub3d *cub3d);
#endif
