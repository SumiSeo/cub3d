/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:38 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/22 20:20:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OUT_OF_BOUND -3

//keeping NULL check useful?
static __int8_t	fill_map(t_parsing *data, short int y, short int x)
{
	char				**map;
	short int			*rows;
	static short int	len_y = 0;

	if (len_y == 0)
		len_y = find_len_strs(&data->file[data->map_beginning]);
	map = data->map;
	rows = data->rows_lens;
	if (x < 0 || y < 0 || y > len_y || x > ft_strlen(map[y])
		|| map[y][x] == '1' || map[y][x] == '2' || !map[y] || !map[y][x])
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
				map[i][j] = '1';
			else if (map[i][j] == -32)
				return (*y = i, *x = j, MAP_NOT_CLOSED);
		}
	}
	return (SUCCESS);
}

__int8_t	is_closed_map(t_parsing *data, short int *y, short int *x)
{
	t_pos	pos;

	pos = find_player(data->map);
	fill_map(data, pos.y, pos.x);
	return (reset_and_check_map(data->map, y, x));
}
