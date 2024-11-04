/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/04 15:24:51 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_launch(t_data *data, t_parsing *parsing)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, "cub 3D");
	data->posX = parsing->posX;
	data->posY = parsing->posY;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->moveSpeed = 0.2;
	data->rotSpeed = 0.2;
	data->mlx.parsing = parsing;
}

void	img_launch(t_mlx *mlx)
{
	mlx->minimap.img_ptr = mlx_new_image(mlx->mlx_ptr, MINIMAP_WIDTH,
			MINIMAP_HEIGHT);
	mlx->minimap.data = (int *)mlx_get_data_addr(mlx->minimap.img_ptr,
			&mlx->minimap.bits_per_pixel, &mlx->minimap.line_length,
			&mlx->minimap.endian);
	mlx->map.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->map.data = (int *)mlx_get_data_addr(mlx->map.img_ptr,
			&mlx->map.bits_per_pixel, &mlx->map.line_length, &mlx->map.endian);
	ft_bzero(mlx->map.data, WIDTH * HEIGHT * sizeof(int));
}

int	map_loop(t_data *data)
{
	// **please keep this line for now ** minimap//
	// draw_squares(mlx);
	// draw_hero(mlx);
	// draw_lines(mlx);
	// draw_rays(mlx);
	// **please keep this line for now ** minimap//
	// mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win);
	ft_bzero(data->mlx.map.data, HEIGHT * WIDTH * sizeof(int));
	draw_rays(data);
	return (0);
}

void	launch_game(t_parsing *parsing, t_screen *screen)
{
	t_data	data;

	(void)screen;
	// data.mlx.mlx_ptr = mlx_init();
	memory_handler(parsing, true);
	mlx_launch(&data, parsing);
	img_launch(&data.mlx);
	mlx_loop_hook(data.mlx.mlx_ptr, &map_loop, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_PRESS, 1L << 0, &key_event, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_EXIT, 0, &mlx_loop_end, data.mlx.mlx_ptr);
	mlx_loop(data.mlx.mlx_ptr);
	mlx_destroy_image(data.mlx.mlx_ptr, data.mlx.map.img_ptr);
	mlx_destroy_image(data.mlx.mlx_ptr, data.mlx.minimap.img_ptr);
	free_arrs((void **)data.mlx.parsing->file);
	free(data.mlx.parsing->rows_lens);
	free(data.mlx.parsing);
	mlx_destroy_window(data.mlx.mlx_ptr, data.mlx.win);
	mlx_destroy_display(data.mlx.mlx_ptr);
	free(data.mlx.mlx_ptr);
}
