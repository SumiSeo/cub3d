/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 21:17:51 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step(t_data *info)
{
	if (info->ray_dir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->pos_x - info->map_x) * info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->pos_x)
			* info->delta_dist_x;
	}
	if (info->ray_dir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->pos_y - info->map_y) * info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->pos_y)
			* info->delta_dist_y;
	}
}
void	init_ray(t_data *info, int x)
{
	info->camera_x = 2 * x / (double)WIDTH - 1;
	info->ray_dir_x = info->dir_x + info->plane_x * info->camera_x;
	info->ray_dir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	info->delta_dist_x = fabs(1 / info->ray_dir_x);
	info->delta_dist_y = fabs(1 / info->ray_dir_y);
	init_step(info);
}
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
void	draw_rays(t_data *info)
{
	int		x;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		hit;
	int		size_y;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;

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
		if (info->side == 0)
			perp_wall_dist = (info->map_x - info->pos_x + (1 - info->step_x)
					/ 2) / info->ray_dir_x;
		else
			perp_wall_dist = (info->map_y - info->pos_y + (1 - info->step_y)
					/ 2) / info->ray_dir_y;
		line_height = (int)(HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		if (info->side == 0)
			wall_x = info->pos_y + perp_wall_dist * info->ray_dir_y;
		else
			wall_x = info->pos_x + perp_wall_dist * info->ray_dir_x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)TEX_WIDTH);
		if (info->side == 0 && info->ray_dir_x > 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		if (info->side == 1 && info->ray_dir_y < 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		step = 1.0 * TEX_HEIGHT / line_height;
		tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			tex_num = find_texture(info->ray_dir_x, info->ray_dir_y,
					info->side);
			tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			color = info->texture[tex_num][TEX_HEIGHT * tex_y + tex_x];
			if (info->side == 1)
				color = (color >> 1) & 8355711;
			put_pixel_to_img(&info->mlx.map, x, y, color);
		}
		draw_floor_ceiling(info, x, draw_start, draw_end);
		x++;
	}
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win,
		info->mlx.map.img_ptr, 0, 0);
}
