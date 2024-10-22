/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/22 15:15:09 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs.h"

//									--> UTILS

char		*merge_strings(char *s1, char *s2, char c);
bool		find_char(char *str, char c);

//									-> PARSING

//-> create_map.c

char		**create_strs(int fd, char sep);
char		**create_file(char *path);
t_parsing	init_pars(char *path);

// handler
void		print_err_msg(char *msg, int fd);

// parsing/bg_parsing.c
int			bg_parsing(t_parsing parsing);

// visualizing/launch_3d.c
void		launch_game(t_parsing parsing);
#endif //__CUB3D__H