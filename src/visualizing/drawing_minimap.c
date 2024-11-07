/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:55:17 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/07 16:01:40 by sumseo           ###   ########.fr       */
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
			}
			j++;
		}
		i++;
	}
}
