/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:40:59 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/08 10:48:32 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * @param file An array of strings containing everything inside the .cub's file.
 * @param infos An array of strings containing only informations about the map
 * (color and textures).
 * @param map An array of strings containing only the map part
 * of the .cub's file.
 */
typedef struct s_parsing
{
	short int	map_beginning;
	short int	row;
	short int	column;
	int			width;
	int			height;
	double		pos_x;
	double		pos_y;
	char		**file;
	char		**map;
	char		*filename;
	short int	*rows_lens;
}				t_parsing;

typedef struct s_screen
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor[3];
	int			ceiling[3];
	int			floor_color;
	int			ceiling_color;
	int			start_x;
	int			start_y;
}				t_screen;

typedef struct s_image
{
	void		*img_ptr;
	int			*data;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_parsing	*parsing;
	t_image		minimap;
	t_image		map;
	t_screen	*screen;
}				t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	int			*texture[8];
	int			buf[HEIGHT][WIDTH];
	int			re_buf;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;

}				t_data;
typedef struct s_key
{
	int			x;
	int			y;
	char		str[3];
}				t_key;

#endif // __STRUCTS__H