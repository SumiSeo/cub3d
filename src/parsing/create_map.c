/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:32:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/04 15:25:06 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define VALID_FIRST_CHARS "NEWSFC"
#define NO_MAP_FOUND -1

// CAREFUL of ft_error : first free memory and then call it

/**
 * @brief Finds the beginning of the map in an array of strings.
 * The beginning of the map is on any line that doesn't start with
 * the characters "NEWSFC\n".
 * @param file The file converted as an array of strings.
 * @returns The index at which the map begins, or -1 if it is not found.
 */
short int	find_map(char **file)
{
	short int	i;

	i = -1;
	while (file[++i])
	{
		if (!is_in_set(file[i][0], VALID_FIRST_CHARS) && file[i][0] != '\n')
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
		return (NO_MAP_FOUND);
	while (file[map_start])
	{
		if (ft_strlen(file[map_start]) == 0 || file[map_start][0] == '\n')
			return (true);
		map_start++;
	}
	return (false);
}

/**
 * @brief Converts a file into an array of strings, while checking
 * if the map's component of the file has empty spaces.
 * @param data A pointer to a structure containing informations about the file.
 * Used for leak-handling purposes.
 * @param path The path to the file.
 * @param ret Norm issues.
 * @returns The file as an array of strings, or NULL if an error occured
 * (empty space, issue with file opening or allocation failure).
 */
char	**create_file(t_parsing *data, char *path, __int8_t ret)
{
	char		**file;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_err_msg("Unable to open file.", fd);
	file = create_strs(fd, -32);
	if (!file)
		print_err_msg(MKO, fd);
	data->file = file;
	memory_handler(data, true);
	ret = check_empty_space(file);
	if (ret == true)
		print_err_msg("Empty space found in file", fd);
	else if (ret == NO_MAP_FOUND)
		print_err_msg("No map found", fd);
	free_arrs((void **)file);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_err_msg("Unable to open file.", fd);
	file = create_strs(fd, '\n');
	if (!file)
		print_err_msg(MKO, fd);
	return (close(fd), file);
}
