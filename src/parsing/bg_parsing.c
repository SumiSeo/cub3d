/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/24 17:46:06 by sumseo           ###   ########.fr       */
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
		{
			return (1);
		}
		if (flag == 1)
			screen->floor[j++] = converted;
		else
			screen->ceiling[j++] = converted;
		i++;
	}
	return (0);
}
int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b)
{
	return (*(int *)(unsigned char[4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
int	hexcolor(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	convert_hex(t_screen *screen)
{
	unsigned char	r;
	unsigned char	g;
	int				col;

	// int	trgb;
	(void)screen;
	r = get_r(screen->floor[0]);
	g = get_g(screen->floor[1]);
	printf("R : %c\n", r);
	printf("G : %c\n", g);
	col = hexcolor(screen->floor[0], screen->floor[1], screen->floor[2]);
	printf("hex color %d\n", col);
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
		{
			free_arrs((void **)split);
			return ;
		}
		else
			convert_hex(screen);
	}
	else if (ft_strncmp("C", place, 1) == 0)
	{
		if (range_check(split, screen, 2))
		{
			free_arrs((void **)split);
			return ;
		}
		else
			convert_hex(screen);
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
		{
			assign_colors(&screen, "F", parsing.file[i]);
			printf("Screen floor color -> %d\n", screen.floor[0]);
		}
		else if (ft_strncmp(parsing.file[i], "C", 1) == 0
			&& parsing.file[i][1] == ' ')
		{
			assign_colors(&screen, "C", parsing.file[i]);
		}

		i++;
	}
	if (!screen.north || !screen.south || !screen.east || !screen.west
		|| !(*screen.floor) || !(*screen.ceiling))
		return (1);
	return (0);
}