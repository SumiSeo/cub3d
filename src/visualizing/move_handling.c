/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:45 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 16:50:45 by sumseo           ###   ########.fr       */
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
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->dirX;
	data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY
		* sin(-data->rotSpeed);
	data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY
		* cos(-data->rotSpeed);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY
		* sin(-data->rotSpeed);
	data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY
		* cos(-data->rotSpeed);
}

void	move_right(t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->dirX;
	data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY
		* sin(data->rotSpeed);
	data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY
		* cos(data->rotSpeed);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY
		* sin(data->rotSpeed);
	data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY
		* cos(data->rotSpeed);
}
