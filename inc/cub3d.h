/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/21 17:49:06 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D__H
# define __CUB3D__H

# include "libs.h"

//									--> UTILS

char	*merge_strings(char *s1, char *s2, char c);


//									-> PARSING

char	**create_map(int fd);

// handler
int	print_err_msg(char *msg);

// bg_parsing.c
int	bg_parsing(char *argv);
#endif //__CUB3D__H