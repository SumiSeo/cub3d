/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/26 20:05:14 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs.h"

//									-> UTILS
//->utils.c

char		*merge_strings(char *s1, char *s2, char c);
bool		is_in_set(char c, char *set);
t_pos		find_player(char **map);

//									-> PARSING
//-> create_map.c

short int	find_map(char **file);
char		**create_strs(int fd, char sep);
char		**create_file(t_parsing *data, char *path, __int8_t ret);
t_parsing	*init_pars_struct(char *path);

//->check_map.c

void		transform_space_in_wall(char **map);
__int8_t	check_characters_in_map(char **map, short int *y, short int *x);

//->parse_map.c

__int8_t	parse_map(t_parsing *data);

//->is_closed_map

__int8_t	is_closed_map(t_parsing *data, short int *y, short int *x);

// ->bg_parsing.c
int			bg_parsing(t_parsing parsing, t_screen screen);

// ->debugging.c
void		print_screen(t_screen screen);

// ->color_parsing.c
void		assign_colors(t_screen *screen, char *place, char *color_arr);
void		convert_hex(t_screen *screen, int i);
int			range_check(char **arr, t_screen *screen, int flag);
int			is_valid_split(char *str);

//								-->HANDLER
//->error_handler.c

void		print_err_msg(char *msg, int fd);

//->memory_handler.c

void		memory_handler(t_parsing *data, bool store);

// visualizing/launch_3d.c
void		launch_game(t_parsing parsing);
int			call(void);
#endif //__CUB3D__H