/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:32:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/21 20:32:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define VALID_FIRST_CHARS "NEWSFC"
#define NO_MAP_FOUND -1

// CAREFUL of ft_error : first free memory and then call it

/**
 * @brief Finds the beginning of the map in an array of strings.
 * @param file The file converted as an array of strings.
 * @returns The index at which the map begins, or -1 if it is not found.
 */
short int	find_map(char **file)
{
	short int	i;

	i = -1;
	while (file[++i])
	{
		if (!find_char(VALID_FIRST_CHARS, file[i][0]) && file[i][0] != '\n')
			return (i);
	}
	return (-1);
}

/**
 * @brief
 * @param fd The file descriptor of the map's file.
 * @param sep The sep on which to split. If sep is -32, then a first array
 * of strings is created, and it is checked for empty spaces.
 * If sep is '\n', then the final array of strings is created.
 * @returns The file as an array of strings.
 */
char	**create_strs(int fd, char sep)
{
	char	*tmp;
	char	*gnl;
	char	**file;

	gnl = get_next_line(fd, 0);
	if (!gnl)
		return (NULL);
	tmp = NULL;
	while (gnl)
	{
		tmp = merge_strings(tmp, gnl, sep);
		free(gnl);
		if (!tmp)
			return (get_next_line(fd, 1), NULL);
		gnl = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	file = ft_split(tmp, sep);
	free(tmp);
	if (!file)
		return (get_next_line(fd, 1), NULL);
	return (file);
}

/**
 * @brief Checks for empty spaces in the map.
 * @param file The file as an array of strings.
 * @returns True (1) if there is one empty string in the map
 * and false (0) otherwise.
 */
__int8_t	check_empty_space(char **file)
{
	short int	map_start;

	map_start = find_map(file);
	if (map_start == -1)
		return (free_arrs((void **)file), NO_MAP_FOUND);
	while (file[map_start])
	{
		if (ft_strlen(file[map_start]) == 0 || file[map_start][0] == '\n')
			return (free_arrs((void **)file), true);
		map_start++;
	}
	free_arrs((void **)file);
	return (false);
}

/**
 * @brief Converts a file into an array of strings, while checking
 * if the map's component of the file has empty spaces.
 * @param path The path to the file.
 * @returns The file as an array of strings, or NULL if an error occured
 * (empty space, issue with file opening or allocation failure).
 * 
 * NOTE : If there is an issue with empty spaces, the strings' array is freed in
 * checke_empty_spaces.
 */
char	**create_file(char *path)
{
	char	**file;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_err_msg("Unable to open file.", fd);
	file = create_strs(fd, -32);
	if (!file)
		print_err_msg(MKO, fd);
	if (check_empty_space(file) == true)
		print_err_msg("Empty space found in file", fd);
	close(fd);
	open(path, O_RDONLY);
	if (fd == -1)
		print_err_msg("Unable to open file.", fd);
	file = create_strs(fd, '\n');
	if (!file)
		print_err_msg(MKO, fd);
	close(fd);
	return (file);
}

//need to protet if crate_file fails since it exits ?
t_parsing	init_pars(char *path)
{
	t_parsing	data;
	char		**file;

	file = create_file(path);
	if (!file)
		print_err_msg("kaka", -1);
	data.file = file;
	data.map_beginning = find_map(file);
	return (data);
}
