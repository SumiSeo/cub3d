/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/18 12:42:04 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define NOT_EXISTING_TEXTURE "Issue with opening one texture file"
#define MISSING_TEXTURE_OR_COLOR "Colors' informations or texture(s) not found"
#define EXCESSIVE_INFORMATIONS "Only four textures and two colors are expected."

short int	start_texture(char *str, char side)
{
	short int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == side)
		{
			i += 2;
			while (str[i] && str[i] == ' ')
				i++;
			return (i);
		}
	}
	return (-1);
}

void	adjust_texture_ptr(t_screen *screen)
{
	screen->north = screen->north + start_texture(screen->north, 'N');
	screen->east = screen->east + start_texture(screen->east, 'E');
	screen->west = screen->west + start_texture(screen->west, 'W');
	screen->south = screen->south + start_texture(screen->south, 'S');
}

bool	check_if_textures_exist(t_screen *screen)
{
	int	fd;

	adjust_texture_ptr(screen);
	fd = open(screen->north, O_RDONLY);
	if (fd == -1)
		print_err_msg(NOT_EXISTING_TEXTURE, -1);
	close(fd);
	fd = open(screen->east, O_RDONLY);
	if (fd == -1)
		print_err_msg(NOT_EXISTING_TEXTURE, -1);
	close(fd);
	fd = open(screen->south, O_RDONLY);
	if (fd == -1)
		print_err_msg(NOT_EXISTING_TEXTURE, -1);
	close(fd);
	fd = open(screen->west, O_RDONLY);
	if (fd == -1)
		print_err_msg(NOT_EXISTING_TEXTURE, -1);
	close(fd);
	return (true);
}

void	parsing_texture(t_parsing *parsing, t_screen *screen, int i)
{
	char	**infos;
	int		len_strs;

	infos = ft_split(parsing->file[i], ' ');
	if (!infos)
		print_err_msg(MKO, -1);
	len_strs = find_len_strs(infos);
	if (len_strs >= 2 && ft_strncmp("NO", infos[0], 2) == 0 && infos[1])
		screen->north = parsing->file[i];
	else if (len_strs >= 2 && ft_strncmp("SO", infos[0], 2) == 0 && infos[1])
		screen->south = parsing->file[i];
	else if (len_strs >= 2 && ft_strncmp("WE", infos[0], 2) == 0 && infos[1])
		screen->west = parsing->file[i];
	else if (len_strs >= 2 && ft_strncmp("EA", infos[0], 2) == 0 && infos[1])
		screen->east = parsing->file[i];
	else if (len_strs >= 2 && ft_strncmp("F", infos[0], 1) == 0 && infos[1])
		assign_colors(screen, "F", parsing->file[i], infos);
	else if (len_strs >= 2 && ft_strncmp("C", infos[0], 1) == 0 && infos[1])
		assign_colors(screen, "C", parsing->file[i], infos);
	free_arrs((void **)infos);
}

int	bg_parsing(t_parsing *parsing, t_screen *screen)
{
	int					i;
	static const char	*map_info[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	i = 0;
	while (parsing->file[i] && i < parsing->map_beginning)
	{
		if (map_info[i] == NULL)
			print_err_msg(EXCESSIVE_INFORMATIONS, -1);
		parsing_texture(parsing, screen, i);
		i++;
	}
	if (!screen->north || !screen->south || !screen->east || !screen->west
		|| screen->floor_color < 0 || screen->ceiling_color < 0)
		print_err_msg(MISSING_TEXTURE_OR_COLOR, -1);
	check_if_textures_exist(screen);
	return (0);
}
