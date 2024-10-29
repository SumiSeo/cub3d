/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:40:59 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/29 17:36:27 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image	t_image;

/**
 * @param file An array of strings containing everything inside the .cub's file.
 * @param infos An array of strings containing only informations about the map
 * (color and textures).
 * @param map An array of strings containing only the map part
 * of the .cub's file.
 */
typedef struct s_parsing
{
	char				**file;
	char				**map;
	char				*filename;
	short int			*rows_lens;
	short int			map_beginning;
	short int			row;
	short int			column;
}						t_parsing;

typedef struct s_pos
{
	short int			x;
	short int			y;
}						t_pos;

typedef struct s_screen
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	int					floor[3];
	int					ceiling[3];
	int					floor_color;
	int					ceiling_color;
	int					start_x;
	int					start_y;
}						t_screen;

typedef struct s_image
{
	void				*img_ptr;
	int					*data;
	void				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_image;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_parsing			*parsing;
	t_image				img;
	t_screen			*screen;
}						t_mlx;

typedef struct s_key
{
	int					x;
	int					y;
	char				str[3];
}						t_key;

typedef struct s_vector
{
	double	x;
	double	y;	
}				t_vector;

typedef struct s_raycasting
{
	double		camera_x;
	t_vector	player;
	t_vector	plane;
	t_vector	direction;
	t_vector	ray_direction;
	t_vector	side_dist;
	t_vector	delta_dist;
}				t_raycasting;

#endif // __STRUCTS__H