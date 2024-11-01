/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 13:49:13 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verLine(t_mlx *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->win, x, y, color);
		y++;
	}
}

void	init_rays(t_ray *rays, int pos_x, int pos_y)
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
}
void	draw_rays_2(t_mlx *mlx)
{
	t_ray	*rays;
	int		x;
	int		mapX;
	int		mapY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		hit;
	int		side;

	rays = malloc(sizeof(t_ray));
	init_rays(rays, 4, 5);
	x = 0;
	while (x < WIDTH)
	{
		rays->camera_int = 2 * x / (double)WIDTH - 1;
		rays->ray_dir.x = rays->dir.x + rays->plane.x * rays->camera_int;
		rays->ray_dir.y = rays->dir.y + rays->plane.y * rays->camera_int;
		mapX = (int)rays->player.x;
		mapY = (int)rays->player.y;
		rays->delta_dist.x = fabs(1 / rays->ray_dir.x);
		rays->delta_dist.y = fabs(1 / rays->ray_dir.y);
		hit = 0;
		if (rays->ray_dir.x < 0)
		{
			stepX = -1;
			rays->side_dist.x = (rays->player.x - mapX) * rays->delta_dist.x;
		}
		else
		{
			stepX = 1;
			rays->side_dist.x = (mapX + 1.0 - rays->player.x)
				* rays->delta_dist.x;
		}
		if (rays->ray_dir.y < 0)
		{
			stepY = -1;
			rays->side_dist.y = (rays->player.y - mapY) * rays->delta_dist.y;
		}
		else
		{
			stepY = 1;
			rays->side_dist.y = (mapY + 1.0 - rays->player.y)
				* rays->delta_dist.y;
		}
		while (hit == 0)
		{
			if (rays->side_dist.x < rays->side_dist.y)
			{
				rays->side_dist.x += rays->delta_dist.x;
				mapX += stepX;
				side = 0;
			}
			else
			{
				rays->side_dist.y += rays->side_dist.y;
				mapY += stepY;
				side = 1;
			}
			if (mlx->parsing->map[mapX][mapY] != '0')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - rays->player.x + (1 - stepX) / 2)
				/ rays->ray_dir.x;
		else
			perpWallDist = (mapY - rays->player.y + (1 - stepY) / 2)
				/ rays->ray_dir.y;
		lineHeight = (int)(HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		if (mlx->parsing->map[mapY][mapX] == '1')
			color = 0x0000FF; // blue
		else if (mlx->parsing->map[mapY][mapX] == '0')
			color = 0xFF0000; // red
		else
			color = 0x0000FF;
		if (side == 1)
			color = color / 2;
		verLine(mlx, x, drawStart, drawEnd, color);
		x++;
	}
}
