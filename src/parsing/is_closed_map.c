/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:38 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/25 15:25:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OUT_OF_BOUND -3

/**
 * @brief Recursively flood-fills the map and checks for an opening.
 * The flood fill start at the player's position. This implies that
 * any opening that is not accessible to the player isn't considered
 * an error.
 * @param data A pointer to a structure containing informations about the file.
 * @param y The line position.
 * @param x The column position.
 * @returns 0 if the recursion can't continue, -1 if an opening is found
 * and 1 if none of these cases were encountered.
 */
static __int8_t	fill_map(t_parsing *data, short int y, short int x)
{
	char				**map;
	short int			*rows;
	static short int	len_y = 0;

	if (len_y == 0)
		len_y = find_len_strs(data->map);
	map = data->map;
	rows = data->rows_lens;
	if (x < 0 || y < 0 || y > len_y || x > ft_strlen(map[y]) || map[y][x] == '1'
		|| map[y][x] == '2' || !map[y] || !map[y][x])
		return (0);
	if (map[y][x] == '0')
		map[y][x] = '2';
	if (map[y][x] == '2' && (rows[y + 1] < x || (y > 0 && rows[y - 1] < x)))
		return (map[y][x] = -32, -1);
	fill_map(data, y, x - 1);
	fill_map(data, y - 1, x);
	fill_map(data, y, x + 1);
	fill_map(data, y + 1, x);
	return (true);
}

/**
 * @brief After flood filling the map, changes to its previous configuration
 * while checking for an opening that is accessible to the player.
 * @param map A pointer to an array of strings containing the map.
 * @param y A pointer to the line number at which an opening is found, if
 * one is found.
 * @param x A pointer to the column number at which an opening is found, if
 * one is found.
 * @returns -4 if an opening is found (MAP_NOT_CLOSED) or 1 (SUCCESS) if it
 * is not the case.
 */
static __int8_t	reset_and_check_map(char **map, short int *y, short int *x)
{
	short int	i;
	short int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
				map[i][j] = '0';
			else if (map[i][j] == -32)
				return (*y = i, *x = j, MAP_NOT_CLOSED);
		}
	}
	return (SUCCESS);
}

/**
 * @brief Checks if the map is closed. If it is not, checks if the player
 * can access this opening.
 * @param data A pointer to a structure containing informations about the file.
 * @param y A pointer to the line number at which an opening is found, if
 * one is found.
 * @param x A pointer to the column number at which an opening is found, if
 * one is found.
 * @returns -4 if an accessible opening is found (MAP_NOT_CLOSED)
 * or 1 (SUCCESS) if it is not the case.
 */
__int8_t	is_closed_map(t_parsing *data, short int *y, short int *x)
{
	t_pos	pos;

	pos = find_player(data->map);
	fill_map(data, pos.y, pos.x);
	return (reset_and_check_map(data->map, y, x));
}
