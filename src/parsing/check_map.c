/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:11:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/21 16:28:31 by sokaraku         ###   ########.fr       */
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

// CAREFUL of ft_error : first free memory and then call it

// char	**create_map(char *file)
// {
// 	int		fd;
// 	char	*tmp;
// 	char	**map;

// 	fd = open(file, O_RDONLY);
// 	// if (fd == -1)
// 	// 	ft_error("Unable to open map's file.");
// }
/**
 * @brief Checks the validity of one character.
 * @param c The character to check
 * @returns True (1) if the character is valid and false (0) otherwise.
 */
bool	is_valid_character(char c)
{
	__int8_t	i;

	i = -1;
	while (ALLOWED_CHARACTERS[++i])
	{
		if (c == ALLOWED_CHARACTERS[i])
			return (true);
	}
	return (false);
}

bool	forbidden_characters(char **map)
{
	short int	i;
	short int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (!(is_valid_character(map[i][j])))
				return (false);
		}
		j = -1;
	}
	return (true);
}
