/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:45 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/07 16:16:28 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_data *data)
{
	if (data->mlx.parsing->map[(int)(data->posX + data->dirX
			* data->moveSpeed)][(int)(data->posY)] == '0')
		data->posX += data->dirX * data->moveSpeed;
	if (data->mlx.parsing->map[(int)(data->posX)][(int)(data->posY + data->dirY
			* data->moveSpeed)] == '0')
		data->posY += data->dirY * data->moveSpeed;
}

void	move_down(t_data *data)
{
	if (data->mlx.parsing->map[(int)(data->posX - data->dirX
			* data->moveSpeed)][(int)(data->posY)] == '0')
		data->posX -= data->dirX * data->moveSpeed;
	if (data->mlx.parsing->map[(int)(data->posX)][(int)(data->posY - data->dirY
			* data->moveSpeed)] == '0')
		data->posY -= data->dirY * data->moveSpeed;
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = data->mlx.parsing->map;
	new_x = data->posX + data->dirY * data->moveSpeed;
	new_y = data->posY - data->dirX * data->moveSpeed;
	if (map[(int)data->posY][(int)new_x] != '1')
	{
		if (map[(int)new_y][(int)data->posX] != '1')
		{	
			data->posX = new_x;
			data->posY = new_y;
		}
	}

}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = data->mlx.parsing->map;
	new_x = data->posX - data->dirY * data->moveSpeed;
	new_y = data->posY + data->dirX * data->moveSpeed;
	if (map[(int)data->posY][(int)new_x] != '1')
	{
		if (map[(int)new_y][(int)data->posX] != '1')
		{
			data->posX = new_x;
			data->posY = new_y;
		}
	}
}
