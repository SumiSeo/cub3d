/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:41:12 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/04 15:25:24 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

int	key_event(int key_code, t_data *data)
{
	printf("Key event detected: %d\n", key_code);
	if (key_code == KEY_DOWN)
		move_down(data);
	else if (key_code == KEY_UP)
		move_up(data);
	else if (key_code == KEY_LEFT)
		move_left(data);
	else if (key_code == KEY_RIGHT)
		move_right(data);
	else if (key_code == KEY_LOOK_RIGHT)
		move_look_right(data);
	else if (key_code == KEY_LOOK_LEFT)
		move_look_left(data);
	else if (key_code == KEY_ESC)
	{
		// mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.map.img_ptr);
		// mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.minimap.img_ptr);
		// free_arrs((void **)data->mlx.parsing->file);
		// free(data->mlx.parsing->rows_lens);
		// free(data->mlx.parsing);
		// mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
		// mlx_destroy_display(data->mlx.mlx_ptr);
		// free(data->mlx.mlx_ptr);
		// exit(EXIT_FAILURE);
		mlx_loop_end(data->mlx.mlx_ptr);
		// exit_game();
	}
	return (1);
}
