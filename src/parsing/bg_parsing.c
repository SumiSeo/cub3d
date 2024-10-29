/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/29 13:52:49 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_index(const char *str, char c)
{
	char	*ptr;

	ptr = strchr(str, c);
	if (ptr)
		return (ptr - str);
	return (-1);
}

int	bg_parsing(t_parsing *parsing, t_screen *screen)
{
	int					i;
	static const char	*map_info[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	i = 0;
	while (parsing->file[i] && i < parsing->map_beginning)
	{
		if (map_info[i] == NULL)
			return (1);
		if (ft_strncmp("NO", parsing->file[i], 2) == 0
			&& parsing->file[i][2] == ' ')
			screen->north = parsing->file[i];
		else if (ft_strncmp(parsing->file[i], "SO", 2) == 0
			&& parsing->file[i][2] == ' ')
			screen->south = parsing->file[i];
		else if (ft_strncmp(parsing->file[i], "WE", 2) == 0
			&& parsing->file[i][2] == ' ')
			screen->west = parsing->file[i];
		else if (ft_strncmp(parsing->file[i], "EA", 2) == 0
			&& parsing->file[i][2] == ' ')
			screen->east = parsing->file[i];
		else if (ft_strncmp(parsing->file[i], "F", 1) == 0
			&& parsing->file[i][1] == ' ')
			assign_colors(screen, "F", parsing->file[i]);
		else if (ft_strncmp(parsing->file[i], "C", 1) == 0
			&& parsing->file[i][1] == ' ')
			assign_colors(screen, "C", parsing->file[i]);
		i++;
	}
	print_screen(screen);
	if (!screen->north || !screen->south || !screen->east || !screen->west
		|| !screen->floor_color || !screen->ceiling_color)
		return (1);
	return (0);
}
