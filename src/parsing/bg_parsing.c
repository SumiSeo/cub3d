/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/24 12:41:11 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_colors(t_screen *screen, char *place, char *color_arr)
{
	int	i;

	i = 0;
	if (ft_strncmp("F", place, 1) == 0)
		screen->floor = &color_arr[1];
	else if (ft_strncmp("C", place, 1) == 0)
		screen->ceiling = &color_arr[1];
}
int	bg_parsing(t_parsing parsing, t_screen screen)
{
	int i = 0;
	while (parsing.file[i] && i < parsing.map_beginning)
	{
		if (ft_strncmp("NO", parsing.file[i], 2) == 0
			&& parsing.file[i][2] == ' ')
			screen.north = parsing.file[i];
		else if (ft_strncmp(parsing.file[i], "SO", 2) == 0
			&& parsing.file[i][2] == ' ')
			screen.south = parsing.file[i];
		else if (ft_strncmp(parsing.file[i], "WE", 2) == 0
			&& parsing.file[i][2] == ' ')
			screen.west = parsing.file[i];
		else if (ft_strncmp(parsing.file[i], "EA", 2) == 0
			&& parsing.file[i][2] == ' ')
			screen.east = parsing.file[i];
		else if (ft_strncmp(parsing.file[i], "F", 1) == 0
			&& parsing.file[i][1] == ' ')
			assign_colors(&screen, "F", parsing.file[i]);
		else if (ft_strncmp(parsing.file[i], "C", 1) == 0
			&& parsing.file[i][1] == ' ')
			assign_colors(&screen, "C", parsing.file[i]);
		i++;
	}
	if (!screen.north || !screen.south || !screen.east || !screen.west
		|| !screen.floor || !screen.ceiling)
		return (1);
	return (0);
}