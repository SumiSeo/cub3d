/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:11:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/14 18:09:58 by sokaraku         ###   ########.fr       */
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

bool	check_screen_size(void *mlx_ptr)
{
	int	x;
	int	y;

	mlx_get_screen_size(mlx_ptr, &x, &y);
	if (x < WIDTH || y < HEIGHT)
		return (false);
	return (true);
}

/**
 * @brief If empty spaces are found in the map, changes them in wall ('1')
 * @param map A pointer to an array of strings containing the map.
 * @returns void.
 */
void	transform_whitespace_in_wall(char **map)
{
	short int	i;
	short int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ' || map[i][j] == '\t')
				map[i][j] = '1';
		}
	}
}

/**
 * @brief Checks if the map is composed of only allowed characters "01NEWS" and
 * that there are only one starting position.
 * @param map A pointer to an array of strings containing the map.
 * @param y A pointer to the line number at which an error was found.
 * @param x A pointer to the column number at which an error was found.
 * @returns -1 if a a forbidden character is found (FORBIDDEN_CHARACTER),
 * -2 if there is no starting position (NO_STARTING_POS), -3 if there are
 * multiple starting positions (MULTIPLE_STARTING_POS) and true (1) if none
 * of these errors were found.
 */
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
