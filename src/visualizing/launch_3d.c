/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 13:44:21 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

void	mlx_launch(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub 3D");
}

void	img_launch(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}

int	img_loop(t_mlx *mlx)
{
	// draw_squares(mlx);
	// draw_hero(mlx);
	// draw_lines(mlx);
	// draw_rays(mlx);
	draw_rays_2(mlx);
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int	key_event(int key_code, t_mlx *mlx)
{
	printf("Key event detected: %d\n", key_code);
	if (key_code == KEY_DOWN)
		move_down(mlx);
	else if (key_code == KEY_UP)
		move_up(mlx);
	else if (key_code == KEY_LEFT)
		move_left(mlx);
	else if (key_code == KEY_RIGHT)
		move_right(mlx);
	else if (key_code == KEY_ESC)
		exit(0);
	return (1);
}

void	launch_game(t_parsing *parsing, t_screen *screen)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(mlx));
	mlx.parsing = parsing;
	mlx.screen = screen;
	mlx_launch(&mlx);
	// img_launch(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &key_event, &mlx);
	mlx_hook(mlx.win, EVENT_KEY_EXIT, 0, &close_game, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &img_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
