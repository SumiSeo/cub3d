/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:45 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/06 15:50:33 by sokaraku         ###   ########.fr       */
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
	// printf("we re in %c\n", map[(int)(new_y - data->dirX
			// * data->moveSpeed)][(int)data->posX]);
	// printf("we re in %c\n", map[(int)data->posY][(int)(new_x + data->dirY
			// * data->moveSpeed)]);
	// if ((int)new_y >= find_len_strs(map)
	// 	|| (int)new_x >= ft_strlen(map[(int)data->posX]))
	// 	return ;
	// if (map[(int)(new_y - data->dirX
	// 		* data->moveSpeed)][(int)data->posX] != '1')
	if (map[(int)data->posY][(int)new_x] != '1')
		data->posX = new_x;
	if (map[(int)new_y][(int)data->posX] != '1')
		data->posY = new_y;
	// 	check++;
	// if (map[(int)data->posY][(int)(new_x + data->dirY
	// 		* data->moveSpeed)] != '1')
	// 	check++;
	// if (check == 2)
	// {
	// data->posX = new_x;
	// data->posY = new_y;
	// }
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
		data->posX = new_x;
	if (map[(int)new_y][(int)data->posX] != '1')
		data->posY = new_y;
}