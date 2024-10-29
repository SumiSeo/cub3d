/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:40:59 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/29 12:34:52 by sumseo           ###   ########.fr       */
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

#endif // __STRUCTS__H