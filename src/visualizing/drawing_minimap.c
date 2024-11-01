/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:55:17 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 15:59:17 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_mlx *mlx, int x, int y, int color)
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
			mlx->minimap.data[(y + i) * WIDTH + x + j] = color;
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
				draw_square(mlx, j, i, mlx->screen->ceiling_color);
			else
				draw_square(mlx, j, i, mlx->screen->floor_color);
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
			mlx->minimap.data[(y + i) * WIDTH + x + j] = 0x006400;
			j++;
		}
		i++;
	}
}

void	draw_hero(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->parsing->row)
	{
		j = 0;
		while (j < mlx->parsing->column)
		{
			if (mlx->parsing->map[i][j] == 'N' || mlx->parsing->map[i][j] == 'E'
				|| mlx->parsing->map[i][j] == 'S'
				|| mlx->parsing->map[i][j] == 'W')
			{
				draw_person(mlx, j, i);
				mlx->screen->start_x = j;
				mlx->screen->start_y = i;
				// printf("mlx->screen->start_x  %d\n", mlx->screen->start_x);
				// printf("mlx->screen->start_y  %d\n", mlx->screen->start_y);
			}
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
		mlx->minimap.data[TO_COORD(x1, y1)] = 0xb3b3b3;
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
