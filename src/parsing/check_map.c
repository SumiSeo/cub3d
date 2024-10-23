/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:11:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/23 13:49:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:11:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/21 16:09:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	transform_space_in_wall(char **map)
{
	short int	i;
	short int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
		}
	}
}

__int8_t	check_characters_in_map(char **map, short int *y, short int *x)
{
	short int	i;
	short int	j;
	short int	initial_pos;

	i = -1;
	j = -1;
	initial_pos = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (!(is_in_set(map[i][j], ALLOWED_CHARACTERS_SET)))
				return (*y = i, *x = j, FORBIDDEN_CHARACTER);
			else if (is_in_set(map[i][j], STARTING_POS_SET))
				initial_pos++;
		}
		j = -1;
	}
	if (initial_pos == 0)
		return (NO_STARTING_POS);
	else if (initial_pos > 1)
		return (MULTIPLE_STARTING_POS);
	return (true);
}
