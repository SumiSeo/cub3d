/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/30 16:57:44 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_dda(t_mlx *mlx)
{
	(void)mlx;
}

void	init_rays(t_ray *rays, int pos_x, int pos_y)
{
	rays->camera_x = 0;
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
		// That is why 2*x comes;
		// double cameraX = 2 * x / (double)WIDTH - 1;
		// this is the calculation of vertor of ray
		// double rayDirX = dirX + planeX * cameraX;
		// double rayDirY = dirY + planeY * cameraX;
		// printf(" rayDirX  : %f\n", rayDirX);
		// printf(" rayDirY  : %f\n", rayDirY);

		// (void)rayDirX;
		// (void)rayDirY;
		// draw_line(mlx, rayDirX,0,);
		x++;
	}
}