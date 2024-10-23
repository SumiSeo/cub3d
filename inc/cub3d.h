/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/23 17:49:07 by sokaraku         ###   ########.fr       */
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

char		**create_strs(int fd, char sep);
char		**create_file(char *path);
t_parsing	init_pars(char *path);

//->check_map.c

void		transform_space_in_wall(char **map);
__int8_t	check_characters_in_map(char **map, short int *y, short int *x);

//->parse_map.c

__int8_t	parse_map(t_parsing *data);

//->is_closed_map

__int8_t	is_closed_map(t_parsing *data, short int *y, short int *x);

// 									-->HANDLER
//->error_handler.c

void		print_err_msg(char *msg, int fd);

//->memory_handler.c

void		memory_handler(t_parsing *data, bool store);

// bg_parsing.c
int			bg_parsing(char *argv);
#endif //__CUB3D__H