/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/24 15:33:54 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_index(const char *str, char c)
{
	char	*ptr;

	ptr = strchr(str, c);
	if (ptr)
	{
		return (ptr - str); // Pointer arithmetic to find index
	}
	return (-1); // Character not found
}
int	range_check(char **arr, t_screen *screen, int flag)
{
	int	i;
	int	j;
	int	converted;

	i = 0;
	j = 0; 
	while (arr[i])
	{
		converted = ft_atoi(arr[i]);
		if (converted < 0 || converted > 255)
			return (0);
		if (flag == 1)
			screen->floor[j++] = converted; 
		else
			screen->ceiling[j++] = converted; 
		i++;
	}
	return (1);
}
void	assign_colors(t_screen *screen, char *place, char *color_arr)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(&color_arr[2], ',');
	if (ft_strncmp("F", place, 1) == 0)
	{
		if (range_check(split, screen, 1))
			return ;
	}
	else if (ft_strncmp("C", place, 1) == 0)
	{
		if (range_check(split, screen, 2))
			return ;
	}
	free_arrs((void **)split);
}
int	bg_parsing(t_parsing parsing, t_screen screen)
{
	int i = 0;
	static const char *map_info[] = {"NO", "SO", "WE", "EA", "F", "C"};
	(void)map_info;
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
		|| !(*screen.floor) || !(*screen.ceiling))
		return (1);
	return (0);
}