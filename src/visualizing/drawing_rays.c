/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:05 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/07 18:23:50 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_img(t_image *img, int x, int y, int color)
{
	img->data[y * (img->line_length / sizeof(int)) + x] = color;
}

void	verLine(t_data *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		put_pixel_to_img(&info->mlx.map, x, y, color);
		y++;
	}
}

void	draw_floor_ceiling(t_data *info, int x, int draw_start, int draw_end)
{
	int	y;

	y = 0;
	if (draw_end < 0)
		return ;
	while (y < draw_start)
	{
		put_pixel_to_img(&info->mlx.map, x, y, info->mlx.screen->ceiling_color);
		y++;
	}
	y = draw_end + 1;
	while (y < HEIGHT)
	{
		put_pixel_to_img(&info->mlx.map, x, y, info->mlx.screen->floor_color);
		y++;
	}
}

void	draw_rays(t_data *info)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		hit;
	int		side;
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
		camera_x = 2 * x / (double)WIDTH - 1;
		ray_dir_x = info->dirX + info->planeX * camera_x;
		ray_dir_y = info->dirY + info->planeY * camera_x;
		map_x = (int)info->posX;
		map_y = (int)info->posY;
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (info->posX - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - info->posX) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (info->posY - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - info->posY) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (info->mlx.parsing->map[map_y][map_x] != '0')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - info->posX + (1 - step_x) / 2)
				/ ray_dir_x;
		else
			perp_wall_dist = (map_y - info->posY + (1 - step_y) / 2)
				/ ray_dir_y;
		line_height = (int)(HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		// tex_num = info->mlx.parsing->map[map_x][map_y] - '0';
		tex_num = 4;
		if (side == 0)
			wall_x = info->posY + perp_wall_dist * ray_dir_y;
		else
			wall_x = info->posX + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)texWidth);
		if (side == 0 && ray_dir_x > 0)
			tex_x = texWidth - tex_x - 1;
		if (side == 1 && ray_dir_y < 0)
			tex_x = texWidth - tex_x - 1;
		step = 1.0 * texHeight / line_height;
		tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			tex_y = (int)tex_pos & (texHeight - 1);
			tex_pos += step;
			color = info->texture[tex_num][texHeight * tex_y + tex_x];
			if (side == 1)
				color = (color >> 1) & 8355711;
			put_pixel_to_img(&info->mlx.map, x, y, color);
			// info->buf[y][x] = color;
			// info->re_buf = 1;
		}
		draw_floor_ceiling(info, x, draw_start, draw_end);
		x++;
	}
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win,
		info->mlx.map.img_ptr, 0, 0);
}
