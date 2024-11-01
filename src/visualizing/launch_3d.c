/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 16:00:43 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

void	mlx_launch(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, "cub 3D");
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

int	img_loop(t_data *data)
{
	// draw_squares(mlx);
	// draw_hero(mlx);
	// draw_lines(mlx);
	// draw_rays(mlx);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win);
	ft_bzero(data->mlx.map.data, HEIGHT * WIDTH * sizeof(int));
	draw_rays_2(data);
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
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
	else if (key_code == KEY_ESC)
		exit(0);
	return (1);
}
t_ray	*init_rays(t_ray *rays, int pos_x, int pos_y)
{
	rays->camera_int = 0;
	rays->player.x = pos_x;
	rays->player.y = pos_y;
	rays->dir.x = -1;
	rays->dir.y = 0;
	rays->plane.x = 0;
	rays->plane.y = 0.66;
	rays->ray_dir.x = 0;
	rays->ray_dir.y = 0;
	rays->delta_dist.x = 0;
	rays->delta_dist.y = 0;
	return (rays);
}
void	launch_game(t_parsing *parsing, t_screen *screen)
{
	t_data	data;

	(void)screen;
	data.mlx.mlx_ptr = mlx_init();
	mlx_launch(&data);
	img_launch(&data.mlx);
	data.posX = 4;
	data.posY = 5;
	data.dirX = -1;
	data.dirY = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	data.moveSpeed = 0.05;
	data.rotSpeed = 0.05;
	data.mlx.parsing = parsing;
	mlx_loop_hook(data.mlx.mlx_ptr, &img_loop, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_PRESS, 1L << 0, &key_event, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_EXIT, 0, &close_game, &data);
	mlx_loop(data.mlx.mlx_ptr);
}
