/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:17:01 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/31 19:16:34 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Helper for the call_error_function.
 * @param ret
 * @param y The line number at which an error is found, if any.
 * @param x The column number at which an error is found, if any.
 * @returns void.
 */
static void	error_helper(__int8_t ret, short int y, short int x)
{
	if (ret == FORBIDDEN_CHARACTER)
	{
		ft_putstr_fd("Error\nAllowed characters are 01NEWS\n", STDERR_FILENO);
		ft_putstr_fd("Wrong character in map is at line ", STDERR_FILENO);
		ft_putnbr_fd(y + 1, STDERR_FILENO);
		ft_putstr_fd(", col ", STDERR_FILENO);
		ft_putnbr_fd(x + 1, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		memory_handler(NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (ret == MAP_NOT_CLOSED)
	{
		ft_putstr_fd("Error\nMap is not closed\n", STDERR_FILENO);
		ft_putstr_fd("Opening found in map at line ", STDERR_FILENO);
		ft_putnbr_fd(y + 1, STDERR_FILENO);
		ft_putstr_fd(", col ", STDERR_FILENO);
		ft_putnbr_fd(x + 1, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		memory_handler(NULL, 0);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Prints error depending on a return value.
 * @param ret The return value of a parsing function.
 * @param y The line number at which an error is found, if any.
 * @param x The column number at which an error is found, if any.
 * @returns void.
 */
static void	call_error_function(__int8_t ret, short int y, short int x)
{
	if (ret == FORBIDDEN_CHARACTER)
		error_helper(ret, y, x);
	else if (ret == NO_STARTING_POS)
		print_err_msg("No starting position", -1);
	else if (ret == MULTIPLE_STARTING_POS)
		print_err_msg("Too many starting positions", -1);
	else if (ret == MAP_NOT_CLOSED)
		error_helper(ret, y, x);
}

/**
 * @brief Helper for the init_pars_struct function.
 * Allocate an array of short int containing the len of each line
 * of the map.
 * @param data A pointer to a structure containing informations about the file.
 * @returns void.
 */

short int	find_maximum_col(t_parsing *data)
{
	short int	maximum;
	int			i;

	maximum = data->rows_lens[0];
	i = 0;
	while (data->rows_lens[i])
	{
		if (maximum < data->rows_lens[i])
			maximum = data->rows_lens[i];
		i++;
	}
	return (maximum);
}
static void	init_pars_struct_helper(t_parsing *data)
{
	short int	*rows;
	short int	i;

	rows = malloc(sizeof(short int) * (find_len_strs(data->map) + 1));
	if (!rows)
		return (print_err_msg(MKO, -1), (void)data);
	data->rows_lens = rows;
	i = -1;
	while (data->map[++i])
	{
		*rows = ft_strlen(data->map[i]);
		rows++;
	}
	data->row = i;
	data->column = find_maximum_col(data);
	data->width = data->row * TILE_SIZE;
	data->height = data->column * TILE_SIZE;
	memory_handler(data, true);
}

/**
 * @brief Allocate the parsing structure that will be used to parse the file.
 * Also does some parsing check (empty file, no map, empty line in the map).
 * @param path The path to the .cub file that will be used for the program.
 * @returns The parsing structure. Exits the program if an error is found.
 */
t_parsing	*init_pars_struct(char *path)
{
	t_parsing	*data;
	char		**file;
	short int	map_start;

	data = malloc(sizeof(t_parsing));
	if (!data)
		print_err_msg(MKO, -1);
	ft_bzero(data, sizeof(data));
	data->rows_lens = NULL;
	memory_handler(data, 1);
	file = create_file(data, path, 0);
	data->file = file;
	memory_handler(data, 1);
	map_start = find_map(file);
	if (map_start == -1)
		print_err_msg("No map found", -1);
	data->map = &file[map_start];
	data->map_beginning = map_start;
	data->filename = path;
	init_pars_struct_helper(data);
	return (data);
}

/**
 * @brief Does the final parsing checks
 *
 *  - character checking : Forbidden characters, no starting position
 * or too many starting positon
 *
 *  - map opening : Checks if an opening is found and if it is accessible
 * to the player.
 * @param data A pointer to a structure containing informations about the file.
 * @returns SUCCESS (1) if the map's parsing is successful. Exits the program
 * otherwise.
 */
__int8_t	parse_map(t_parsing *data)
{
	char		**map;
	__int8_t	ret;
	short int	y;
	short int	x;

	map = data->map;
	y = 0;
	x = 0;
	transform_whitespace_in_wall(map);
	ret = check_characters_in_map(map, &y, &x);
	call_error_function(ret, y, x);
	ret = is_closed_map(data, &y, &x);
	call_error_function(ret, y, x);
	return (SUCCESS);
}
