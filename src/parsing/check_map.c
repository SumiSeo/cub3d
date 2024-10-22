/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:11:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/22 20:20:42 by sokaraku         ###   ########.fr       */
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
