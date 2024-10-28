/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/28 15:44:05 by sumseo           ###   ########.fr       */
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

void	draw_square(t_mlx *mlx, int x, int y)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	j = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx->img.data[(y + i) * WIDTH + x + j] = 0xFFFF0F;
			j++;
		}
		i++;
	}
}

void	draw_person(t_mlx *mlx, int x, int y)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	j = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx->img.data[(y + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_squares(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->parsing->row)
	{
		j = 0;
		while (j < mlx->parsing->column)
		{
			if (mlx->parsing->map[i][j] == '1')
				draw_square(mlx, j, i);
			else if (mlx->parsing->map[i][j] == 'N')
				draw_person(mlx, j, i);
			j++;
		}
		i++;
	}
}

void	draw_line(t_mlx *mlx, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		mlx->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < COLS)
	{
		draw_line(mlx, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(mlx, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(mlx, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(mlx, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}
int	img_loop(t_mlx *mlx)
{
	draw_squares(mlx);
	draw_lines(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}
int	key_event(int key_code, t_mlx *mlx)
{
	printf("Key event detected: %d\n", key_code);
	if (key_code == KEY_DOWN)
	{
		printf("key s clicekd\n");
		mlx->parsing->map[0][0] = 'N';
	}
	else if (key_code == KEY_UP)
		printf("key s clicekd\n");
	else if (key_code == KEY_LEFT)
		printf("key s clicekd\n");
	else if (key_code == KEY_RIGHT)
		printf("key s clicekd\n");
	else if (key_code == KEY_ESC)
		exit(0);
	return (1);
}
void	launch_game(t_parsing *parsing)
{
	t_mlx mlx;

	ft_memset(&mlx, 0, sizeof(mlx));
	mlx.parsing = parsing;
	mlx_launch(&mlx);
	img_launch(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &key_event, &mlx);
	mlx_hook(mlx.win, EVENT_KEY_EXIT, 0, &close_game, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &img_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
}