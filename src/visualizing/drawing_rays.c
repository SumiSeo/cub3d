/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 21:43:14 by sumseo           ###   ########.fr       */
/*   Updated: 2024/11/09 20:40:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	avance_side_x(t_data *info)
{
	info->side_dist_x += info->delta_dist_x;
	info->map_x += info->step_x;
	info->side = 0;
}

void	avance_side_y(t_data *info)
{
	info->side_dist_y += info->delta_dist_y;
	info->map_y += info->step_y;
	info->side = 1;
}

void	find_wall_x(t_data *info)
{
	if (info->side == 0)
		info->wall_x = info->pos_y + info->perp_wall_dist * info->ray_dir_y;
	else
		info->wall_x = info->pos_x + info->perp_wall_dist * info->ray_dir_x;
	info->wall_x -= floor(info->wall_x);
	info->line_height = (int)(HEIGHT / info->perp_wall_dist);
	info->tex_x = (int)(info->wall_x * (double)TEX_WIDTH);
	if (info->side == 0 && info->ray_dir_x > 0)
		info->tex_x = TEX_WIDTH - info->tex_x - 1;
	if (info->side == 1 && info->ray_dir_y < 0)
		info->tex_x = TEX_WIDTH - info->tex_x - 1;
	info->step = 1.0 * TEX_HEIGHT / info->line_height;
	info->tex_pos = (info->draw_start - HEIGHT / 2 + info->line_height / 2)
		* info->step;
}

void	find_perp_wall(t_data *info)
{
	if (info->side == 0)
		info->perp_wall_dist = (info->map_x - info->pos_x + (1 - info->step_x)
				/ 2) / info->ray_dir_x;
	else
		info->perp_wall_dist = (info->map_y - info->pos_y + (1 - info->step_y)
				/ 2) / info->ray_dir_y;
	info->draw_start = -info->line_height / 2 + HEIGHT / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_height / 2 + HEIGHT / 2;
	if (info->draw_end >= HEIGHT)
		info->draw_end = HEIGHT - 1;
}

int find_texture(double ray_dir_x, double ray_dir_y, int side)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (EAST); 
		else
			return (WEST);
	}
	else
	{
		if (ray_dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	return (4);
}

void	draw_rays(t_data *info)
{
	int	x;
	int	hit;
	int	size_y;

	size_y = find_len_strs(info->mlx.parsing->map);
	x = 0;
	while (x < WIDTH)
	{
		init_ray(info, x);
		hit = 0;
		while (hit == 0)
		{
			if (info->side_dist_x < info->side_dist_y)
				avance_side_x(info);
			else
				avance_side_y(info);
			if (info->mlx.parsing->map[info->map_y][info->map_x] == '1')
				hit = 1;
		}
		calc_and_draw(info, x);
		x++;
	}
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win,
		info->mlx.map.img_ptr, 0, 0);
}
