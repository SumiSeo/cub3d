/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:17:01 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/24 19:48:16 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	call_error_function(__int8_t ret, short int y, short int x)
{
	if (ret == FORBIDDEN_CHARACTER)
	{
		ft_putstr_fd("Error\nAllowed characters are 01NEWS\n", STDERR_FILENO);
		printf("Wrong character in map is at line %d, col %d\n", y + 1, x + 1);
		memory_handler(NULL, 0);
		exit(EXIT_FAILURE);
	}
	else if (ret == NO_STARTING_POS)
		print_err_msg("No starting position", -1);
	else if (ret == MULTIPLE_STARTING_POS)
		print_err_msg("Too many starting positions", -1);
	else if (ret == MAP_NOT_CLOSED)
	{
		ft_putstr_fd("Error\nMap is not closed\n", STDERR_FILENO);
		printf("Opening found in map at line %d, col %d\n", y + 1, x + 1);
		memory_handler(NULL, 0);
		exit(EXIT_FAILURE);
	}
}

t_parsing	*init_pars(char *path)
{
	t_parsing	*data;
	char		**file;
	short int	*rows;
	short int	map_start;

	data = malloc(sizeof(t_parsing));
	if (!data)
		print_err_msg(MKO, -1);
	ft_bzero(data, sizeof(data));
	data->rows_lens = NULL;
	file = create_file(data, path);
	data->file = file;
	memory_handler(data, 1);
	map_start = find_map(file);
	if (map_start == -1)
		print_err_msg("No map found", -1);
	data->map = &file[map_start];
	rows = malloc(sizeof(short int) * (find_len_strs(data->map) + 1));
	if (!rows)
		return (free_arrs((void **)file), print_err_msg(MKO, -1), data);
	data->rows_lens = rows;
	data->map_beginning = map_start;
	while (file[map_start])
	{
		*rows = ft_strlen(file[map_start]);
		map_start++;
		rows++;
	}
	return (memory_handler(data, 1), *rows = -1, data->filename = path, data);
}

__int8_t	parse_map(t_parsing *data)
{
	char		**map;
	__int8_t	ret;
	short int	y;
	short int	x;

	map = data->map;
	y = 0;
	x = 0;
	transform_space_in_wall(map);
	ret = check_characters_in_map(map, &y, &x);
	call_error_function(ret, y, x);
	ret = is_closed_map(data, &y, &x);
	call_error_function(ret, y, x);
	return (SUCCESS);
}
