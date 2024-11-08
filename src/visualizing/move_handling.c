/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:45 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/08 10:53:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_data *data)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = data->mlx.parsing->map;
	new_x = data->pos_x + data->dir_x * data->move_speed;
	new_y = data->pos_y + data->dir_y * data->move_speed;
	if (map[(int)data->pos_x][(int)new_x] != '1')
		data->pos_x = new_x;
	if (map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

void	move_down(t_data *data)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = data->mlx.parsing->map;
	new_x = data->pos_x - data->dir_x * data->move_speed;
	new_y = data->pos_y - data->dir_y * data->move_speed;
	if (map[(int)data->pos_x][(int)new_x] != '1')
		data->pos_x = new_x;
	if (map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = data->mlx.parsing->map;
	new_x = data->pos_x + data->dir_y * data->move_speed;
	new_y = data->pos_y - data->dir_x * data->move_speed;
	if (map[(int)data->pos_y][(int)new_x] != '1')
		data->pos_x = new_x;
	if (map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = data->mlx.parsing->map;
	new_x = data->pos_x - data->dir_y * data->move_speed;
	new_y = data->pos_y + data->dir_x * data->move_speed;
	if (map[(int)data->pos_y][(int)new_x] != '1')
		data->pos_x = new_x;
	if (map[(int)new_y][(int)data->pos_x] != '1')
		data->pos_y = new_y;
}
