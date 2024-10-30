/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/30 18:23:53 by sumseo           ###   ########.fr       */
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
	rays->side_dist.x = 0;
	rays->side_dist.y = 0;
	rays->delta_dist.x = 0;
	rays->delta_dist.y = 0;
	rays->step_x = 0;
	rays->step_y = 0;
	rays->wall_dist = 0;
	rays->hit = 0;
	rays->side = 0;
}
void	draw_rays(t_mlx *mlx)
{
	t_ray *rays;
	rays = malloc(sizeof(t_ray));
	init_rays(rays, mlx->screen->start_x, mlx->screen->start_y);

	int x = 0;

	printf("x position %d\n", mlx->screen->start_x);
	printf("x position %d\n", mlx->screen->start_y);

	// this loop calculates the direction of each ray based on the player's position,
	//		direction, and the camera plane,
	while (x < WIDTH)
	{
		// Camera range should be between -1 ~ 1;
		rays->camera_int = 2 * x / (double)WIDTH - 1;

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
		// while (rays->hit == 0)
		// {
		// 	if (rays->side_dist.x < rays->side_dist.y)
		// 	{
		// 		rays->side_dist.x += rays->delta_dist.x;
		// 		mapX += rays->step_x;
		// 		rays->side = 0;
		// 	}
		// 	else
		// 	{
		// 		rays->side_dist.y += rays->delta_dist.y;
		// 		mapY += rays->step_x;
		// 		rays->side = 1;
		// 	}
		// 	// check if ray has hit a wall
		// 	if (mlx->parsing->map[mapX][mapY] > 0)
		// 		rays->hit = 1;
		// }

		// calculate hieght of the line to draw on screen

		x++;
	}
}