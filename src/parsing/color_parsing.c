/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/07 21:06:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	only_digit_char(char *str)
{
	short int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

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
		if (is_valid_split(arr[i]) || only_digit_char(arr[i]) == false)
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
	int	color;

	if (i == 1)
	{
		color = (screen->floor[0] & 0x0FF) << 16;
		color |= (screen->floor[1] & 0x0FF) << 8;
		color |= (screen->floor[2] & 0x0FF);
		screen->floor_color = color;
	}
	else
	{
		color = (screen->ceiling[0] & 0x0FF) << 16;
		color |= (screen->ceiling[1] & 0x0FF) << 8;
		color |= (screen->ceiling[2] & 0x0FF);
		screen->ceiling_color = color;
	}
}

void	assign_colors(t_screen *screen, char *place, char *color_arr)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(&color_arr[2], ',');
	if (find_len_strs(split) != 3)
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
