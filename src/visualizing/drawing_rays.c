/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/31 19:16:57 by sumseo           ###   ########.fr       */
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
	// rays->side_dist.x = 0;
	// rays->side_dist.y = 0;
	rays->delta_dist.x = 0;
	rays->delta_dist.y = 0;
	rays->step_x = 0;
	rays->step_y = 0;
	rays->wall_dist = 0;
	rays->hit = 0;
	rays->side = 0;
}

void	draw_rays_2(t_mlx *mlx)
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	old_time;
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
	int		hit;
	int		side;

	posX = mlx->screen->start_x;
	posY = mlx->screen->start_y;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	time = 0;
	old_time = 0;
	x = 0;
	// ray sholud shout as much as pixel width
	while (x < mlx->parsing->width)
	{
		// This is ray vector calculation
		cameraX = 2 * x / (double)mlx->parsing->width - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		mapX = (int)mlx->screen->start_x;
		mapY = (int)mlx->screen->start_y;
		// This is DDA calculation (with this algorithm we can see whether ray touches the wall or not)
		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		// which direction ray should fo further
		hit = 0;
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
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
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
			// Check if ray has hit a wall
			if (mlx->parsing->map[mapX][mapY] > 0)
				hit = 1;
		}
		// if (side == 0)
		// 	perpWallDist = (sideDistX - deltaDistX);
		// else
		// 	perpWallDist = (sideDistY - deltaDistY);
		(void)perpWallDist;
	}
}
void	draw_rays(t_mlx *mlx)
{
	t_ray *rays;
	rays = malloc(sizeof(t_ray));
	init_rays(rays, mlx->screen->start_x, mlx->screen->start_y);

	int x = 0;

	printf("x position %f\n", rays->player.x);
	printf("x position %f\n", rays->player.x);

	// this loop calculates the direction of each ray based on the player's position,
	//		direction, and the camera plane,
	while (x < mlx->parsing->width)
	{
		// Camera range should be between -1 ~ 1;
		rays->camera_int = 2 * x / (double)mlx->parsing->width - 1;

		// this is the calculation of vertor of ray
		rays->ray_dir.x = rays->dir.x + rays->plane.x * rays->camera_int;
		rays->ray_dir.y = rays->dir.y + rays->plane.y * rays->camera_int;
		printf(" rayDirX  : %f\n", rays->ray_dir.x);
		printf(" rayDirY  : %f\n", rays->ray_dir.y);
		int mapX = (int)rays->player.x;
		int mapY = (int)rays->player.y;
		// cacl delta_dist
		rays->delta_dist.x = rays->ray_dir.x == 0 ? 1e30 : fabs(1
				/ rays->ray_dir.x);
		rays->delta_dist.y = rays->ray_dir.y == 0 ? 1e30 : fabs(1
				/ rays->ray_dir.y);

		// check which direction to step in (x or y)
		if (rays->ray_dir.x < 0)
		{
			rays->step_x = -1;
			rays->side_dist.x = (rays->player.x - mapX) * rays->delta_dist.x;
		}

		else
		{
			rays->step_x = 1;
			rays->side_dist.x = (mapX + 1.0 - rays->player.x)
				* rays->delta_dist.x;
		}
		if (rays->ray_dir.y < 0)
		{
			rays->step_y = -1;
			rays->side_dist.y = (rays->player.y - mapY) * rays->delta_dist.y;
		}
		else
		{
			rays->step_y = 1;
			rays->side_dist.y = (mapY + 1.0 - rays->player.y)
				* rays->delta_dist.y;
		}

		// perform dda;

		while (rays->hit == 0)
		{
			printf("rays hit %d\n", rays->hit);
			printf("rays->side_dist.x %f\n", rays->side_dist.x);
			printf("rays->side_dist.y %f\n", rays->side_dist.y);
			if (rays->side_dist.x < rays->side_dist.y)
			{
				// printf("HERE?\n");
				rays->side_dist.x += rays->delta_dist.x;
				mapX += rays->step_x;
				rays->side = 0;
			}
			else
			{
				rays->side_dist.y += rays->delta_dist.y;
				mapY += rays->step_x;
				rays->side = 1;
			}
			// check if ray has hit a wall

			printf("atoi converstion %c\n", mlx->parsing->map[0][0]);
			printf("mapX %d\n", mapX);
			printf("mapY %d\n", mapY);

			if (mlx->parsing->map[mapY][mapX] > 0)
				rays->hit = 1;
		}

		// calculate hieght of the line to draw on screen
		if (rays->side == 0)
			rays->wall_dist = (rays->side_dist.x - rays->delta_dist.x);
		else
			rays->wall_dist = (rays->side_dist.y - rays->delta_dist.y);

		// int line_height = (int)mlx->parsing->height / rays->wall_dist);
		// int draw_start = -line_height / 2 + mlx->parsing->height / 2;
		// if (draw_start < 0)
		// 	draw_start = 0;
		// int draw_end = line_height / 2 + mlx->parsing->height / 2;
		// if (draw_end >= mlx->parsing->height)
		// 	draw_end = mlx->parsing->height - 1;
		// printf("draw start ");
		// draw_line(mlx, 0, 0, draw_start, draw_end);
		// verLine(x, draw_start, draw_end, "0xb3b3b3");
		x++;
	}
}