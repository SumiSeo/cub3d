/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/31 22:13:49 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	calc_dda(t_mlx *mlx, t_ray *rays)
// {
// 	int	mapX;
// 	int	mapY;

// 	// map x and y is current square where ray touches
// 	(void)mlx;

// }
#define width 640
#define height 480

void	init_rays(t_ray *rays, int pos_x, int pos_y)
{
	(void)pos_x;
	(void)pos_y;
	rays->camera_int = 0;
	rays->player.x = 2;
	rays->player.y = 1;
	rays->dir.x = -1;
	rays->dir.y = 0;
	rays->plane.x = 0;
	rays->plane.y = 0.66;
	rays->ray_dir.x = 0;
	rays->ray_dir.y = 0;
	rays->delta_dist.x = 0;
	rays->delta_dist.y = 0;
	rays->step_x = 0;
	rays->step_y = 0;
	rays->wall_dist = 0;
	rays->hit = 0;
	rays->side = 0;
	// printf("pos_x %d\n", pos_x);
}
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
void	draw_rays_2(t_mlx *mlx)
{
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		lineHeight;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	posX;
	double	posY;
	int		hit;
	int		side;

	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	x = 0;
	posX = 5; // Player's starting position
	posY = 3; // Player's starting position
	while (x < width)
	{
		cameraX = 2 * x / (double)width - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		hit = 0;
		// Initialize side distances
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		// Raycasting loop
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Debugging output
			// Check if the ray has hit a wall
			if (mlx->parsing->map[mapX][mapY] != '0')
				hit = 1;
		}
		// Calculate distance to the wall based on which side was hit
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		// Calculate height of line to draw on screen
		lineHeight = (int)(height / perpWallDist);
		drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;
		// Determine color based on the map value
		if (mlx->parsing->map[mapY][mapX] == '1')
			color = 0xFF0000; // Red for walls
		else if (mlx->parsing->map[mapY][mapX] == '0')
			color = 0x00FF00; // Green for free space
		else if (mlx->parsing->map[mapY][mapX] == 'W')
			color = 0x0000FF; // Blue for special walls
		// else
		// 	color = 0xFFFF00; // Yellow for default
		// Reduce color brightness if hit from the side
		if (side == 1)
			color = color / 2;
		// Draw the vertical line for the current column
		verLine(mlx, x, drawStart, drawEnd, color);
		x++;
	}
}
