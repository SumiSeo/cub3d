/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/25 16:04:12 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_split(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r'
			&& str[i] != '\v' && str[i] != '\f')
			return (0);
		i++;
	}
	return (1);
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
		if (is_valid_split(arr[i]))
			return (1);
		converted = ft_atoi(arr[i]);
		if (converted < 0 || converted > 255)
			return (1);
		if (flag == 1)
			screen->floor[j++] = converted;
		else
			screen->ceiling[j++] = converted;
		i++;
	}
	if (i <= 2 || j <= 2)
		return (1);
	return (0);
}
void	convert_hex(t_screen *screen, int i)
{
	if (i == 1)
		screen->floor_color = ((screen->floor[0] & 0x0ff) << 16) | ((screen->floor[1] & 0x0ff) << 8) | (screen->floor[2] & 0x0ff);
	else
		screen->ceiling_color = ((screen->ceiling[0] & 0x0ff) << 16) | ((screen->ceiling[1] & 0x0ff) << 8) | (screen->ceiling[2] & 0x0ff);
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
		convert_hex(screen, 1);
	}
	else if (ft_strncmp("C", place, 1) == 0)
	{
		if (range_check(split, screen, 2))
		{
			free_arrs((void **)split);
			return ;
		}
		convert_hex(screen, 2);
	}
	free_arrs((void **)split);
}
