/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:17:01 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/22 20:20:51 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	call_error_function(__int8_t ret, short int y, short int x)
{
	if (ret == FORBIDDEN_CHARACTER)
	{
		ft_putstr_fd("Error\nAllowed characters are 01NEWS\n", STDERR_FILENO);
		printf("Wrong character is at line %hd, col %hd\n", y, x);
		exit(EXIT_FAILURE);
	}
	else if (ret == NO_STARTING_POS)
		print_err_msg("No starting position", -1);
	else if (ret == MULTIPLE_STARTING_POS)
		print_err_msg("Too many starting positions", -1);
	else if (ret == MAP_NOT_CLOSED)
	{
		ft_putstr_fd("Error\nMap is not closed\n", STDERR_FILENO);
		printf("Opening found at line %hd, col %hd\n", y, x);
		exit(EXIT_FAILURE);
	}
}

__int8_t	parse_map(t_parsing *data)
{
	char		**map;
	__int8_t	ret;
	short int	y;
	short int	x;

	map = &data->file[data->map_beginning];
	y = 0;
	x = 0;
	ret = check_characters_in_map(map, &y, &x);
	call_error_function(ret, y, x);
	ret = is_closed_map(data, &y, &x);
	call_error_function(ret, y, x);
	return (SUCCESS);
}
