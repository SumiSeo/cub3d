/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/18 12:55:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define COLOR_OVERFLOW "Colors' value must be between 0 and 255"
#define COLOR_WRONG_FORMAT "Only positive numeric values allowed for colors."
#define COLOR_TOO_MANY "Only two colors are expected (floor and ceiling)"

bool	only_digit_char(char *str)
{
	short int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == false && str[i] != ' ')
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

int	range_check(char **arr, t_screen *screen, int flag, char **s)
{
	int	i;
	int	j;
	int	converted;

	i = -1;
	j = 0;
	while (arr[++i])
	{
		if (only_digit_char(arr[i]) == false)
			return (free_multiple_arrs(2, (void **)arr, (void **)s),
				print_err_msg(COLOR_WRONG_FORMAT, -1), 1);
		if (is_valid_split(arr[i]))
			return (1);
		converted = ft_atoi(arr[i]);
		if (converted < 0 || converted > 255)
			return (free_multiple_arrs(2, (void **)arr, (void **)s),
				print_err_msg(COLOR_OVERFLOW, -1), 1);
		if (flag == 1)
			screen->floor[j++] = converted;
		else
			screen->ceiling[j++] = converted;
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

void	assign_colors(t_screen *screen, char *place, char *color_arr, char **s)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(&color_arr[start_colors(color_arr)], ',');
	if (!arr)
		return (free(s), print_err_msg(MKO, -1), (void)i);
	if (find_len_strs(arr) != 3)
	{
		free_multiple_arrs(2, (void **)arr, (void **)s);
		print_err_msg(COLOR_TOO_MANY, -1);
	}
	if (ft_strncmp("F", place, 1) == 0)
	{
		if (range_check(arr, screen, 1, s))
			return (free_multiple_arrs(2, (void **)s, (void **)arr), (void)i);
		convert_hex(screen, 1);
	}
	else if (ft_strncmp("C", place, 1) == 0)
	{
		if (range_check(arr, screen, 2, s))
			return (free_multiple_arrs(2, (void **)s, (void **)arr), (void)i);
		convert_hex(screen, 2);
	}
	free_arrs((void **)arr);
}
