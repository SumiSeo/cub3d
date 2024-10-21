/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/21 20:33:21 by sokaraku         ###   ########.fr       */
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
int			print_err_msg(char *msg, int fd);

// bg_parsing.c
int			bg_parsing(char *argv);
#endif //__CUB3D__H