/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:14 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/21 14:51:25 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D__H
# define __CUB3D__H

# include "libs.h"

// handler
int	print_err_msg(char *msg);

// bg_parsing.c
int	bg_parsing(char *argv);
#endif //__CUB3D__H