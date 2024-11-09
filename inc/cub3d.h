/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 21:43:43 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs.h"

//									-> UTILS
//->utils.c

char		*merge_strings(char *s1, char *s2, char c);
bool		is_in_set(char c, char *set);
void		find_player(char **map, double *pos_y, double *pos_x);
short int	find_maximum_col(t_parsing *data);
void		free_textures(int *textures[], __int8_t n);
//									-> PARSING
//-> create_map.c

short int	find_map(char **file);
char		**create_strs(int fd, char sep);
char		**create_file(t_parsing *data, char *path, __int8_t ret);
t_parsing	*init_pars_struct(char *path);

//->check_map.c

void		transform_whitespace_in_wall(char **map);
__int8_t	check_characters_in_map(char **map, short int *y, short int *x);

//->parse_map.c

__int8_t	parse_map(t_parsing *data);

//->is_closed_map

__int8_t	is_closed_map(t_parsing *data, short int *y, short int *x);

// ->bg_parsing.c
int			bg_parsing(t_parsing *parsing, t_screen *screen);

// ->debugging.c
void		print_screen(t_screen *screen);

// ->color_parsing.c
void		assign_colors(t_screen *screen, char *place, char *color_arr);
void		convert_hex(t_screen *screen, int i);
int			range_check(char **arr, t_screen *screen, int flag);
int			is_valid_split(char *str);

//								-->HANDLER
// ->error_handler.c

void		print_err_msg(char *msg, int fd);

// ->memory_handler.c

void		memory_handler(t_parsing *parsing, bool store);

//								-->VISUALIZING
// MOVE_HANDLING.C
int			call(void);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);

// KEY_HANDLIG.c
int			key_event(int key_code, t_data *data);
int			close_game(t_mlx *mlx);

// VIEW_HANDLING.c
void		move_look_right(t_data *data);
void		move_look_left(t_data *data);

// DRAWING_MINIMAP.C
void		draw_square(t_mlx *mlx, int x, int y, int color);
void		draw_person(t_mlx *mlx, int x, int y);
void		draw_squares(t_mlx *mlx);
void		draw_line(t_mlx *mlx, double x1, double y1, double x2, double y2);
void		draw_lines(t_mlx *mlx);
void		draw_hero(t_mlx *mlx);

// DRAWING_RAYS.c
void		draw_rays(t_data *data);
void		put_pixel_to_img(t_image *img, int x, int y, int color);
void		verLine(t_data *info, int x, int y1, int y2, int color);
void		find_wall_x(t_data *info);
void		find_perp_wall(t_data *info);

// LAUNCH_3D.c
void		launch_game(t_parsing *parsing, t_screen *screen);
int			map_loop(t_data *data);
void		set_dir_plane(t_data *data, char direction);

// LAUNCH_MLX.C
void		img_launch(t_mlx *mlx);
void		mlx_launch(t_data *data, t_parsing *parsing, t_screen *screen);
void		launch_texture(t_data *data);
void		init_ray(t_data *info, int x);
void		init_side(t_data *info);

// LAUNCH_RAYCASTING.C
__int8_t	find_texture(double ray_dir_x, double ray_dir_y, int side);
void		put_pixel_to_img(t_image *img, int x, int y, int color);
void		draw_floor_ceiling(t_data *info, int x, int draw_start,
				int draw_end);
void		draw_wall(t_data *info, int x);
void		calc_and_draw(t_data *info, int x);

#endif //__CUB3D__H