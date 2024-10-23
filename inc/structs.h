/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:40:59 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/23 14:06:23 by sokaraku         ###   ########.fr       */
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
	char		**file;
	char		**map;
	char		*filename;
	short int	*rows_lens;
	short int	map_beginning;
}			t_parsing;

typedef struct s_pos
{
	short int	x;
	short int	y;
}				t_pos;

typedef struct s_stack
{
	t_pos			left;
	t_pos			up;
	t_pos			right;
	t_pos			down;
	struct s_stack	*next;
}				t_stack;

#endif // __STRUCTS__H