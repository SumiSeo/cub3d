/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:40:59 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/24 12:42:20 by sumseo           ###   ########.fr       */
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
	char			**file;
	char			**map;
	char			*filename;
	short int		*rows_lens;
	short int		map_beginning;
}					t_parsing;

typedef struct s_pos
{
	short int		x;
	short int		y;
}					t_pos;

typedef struct s_stack
{
	t_pos			left;
	t_pos			up;
	t_pos			right;
	t_pos			down;
	struct s_stack	*next;
}					t_stack;

typedef struct s_screen
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;

}					t_screen;

#endif // __STRUCTS__H