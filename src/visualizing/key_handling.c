/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:41:12 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 17:02:34 by sumseo           ###   ########.fr       */
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
		// move_left(data);
		printf("move left\n");
	else if (key_code == KEY_RIGHT)
		// move_right(data);
		printf("move right\n");
	else if (key_code == KEY_LOOK_RIGHT)
		move_look_right(data);
	else if (key_code == KEY_LOOK_LEFT)
		move_look_left(data);
	else if (key_code == KEY_ESC)
		exit(0);
	return (1);
}
