/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/22 15:55:14 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_colors(char *place, char *color_arr)
{
	(void)place;
	(void)color_arr;
}
void	assign_dir(void)
{
	printf("tn");
}
int	bg_parsing(t_parsing parsing, t_screen screen)
{
	int i = 0;
	const char *info[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	(void)info;
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
		else if (ft_strncmp(parsing.file[i], "F", 1
				&& parsing.file[i][1] == ' ') == 0)
			assign_colors(parsing.file[0], parsing.file[1]);
		else if (ft_strncmp(parsing.file[i], "C", 1
				&& parsing.file[i][2] == ' ') == 0)
			assign_colors(parsing.file[0], parsing.file[1]);
		i++;
	}

	return (0);
}