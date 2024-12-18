/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:46:32 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/08 10:54:44 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rot_speed) - data->dir_y
		* sin(-data->rot_speed);
	data->dir_y = old_dir_x * sin(-data->rot_speed) + data->dir_y
		* cos(-data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->rot_speed) - data->plane_y
		* sin(-data->rot_speed);
	data->plane_y = old_plane_x * sin(-data->rot_speed) + data->plane_y
		* cos(-data->rot_speed);
}

void	move_look_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed) - data->dir_y
		* sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) + data->dir_y
		* cos(data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y
		* sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) + data->plane_y
		* cos(data->rot_speed);
}
