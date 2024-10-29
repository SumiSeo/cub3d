/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/29 14:49:12 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_mlx *mlx)
{
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;
	(void)mlx;
	int x = 0;

	printf("x position %d\n", mlx->screen->start_x);
	printf("x position %d\n", mlx->screen->start_y);
	// this loop calculates the direction of each ray based on the player's position,
	//		direction, and the camera plane,
	while (x < WIDTH)
	{
		// Camera range should be between -1 ~ 1;
		// That is why 2*x comes;
		double cameraX = 2 * x / (double)WIDTH - 1;
		// this is the calculation of vertor of ray
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		printf(" rayDirX  : %f\n", rayDirX);
		printf(" rayDirY  : %f\n", rayDirY);

		// (void)rayDirX;
		// (void)rayDirY;
		// draw_line(mlx, rayDirX,0,);
		x++;
	}
}