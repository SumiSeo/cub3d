/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:03:06 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 21:42:16 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	put_pixel_to_img(t_image *img, int x, int y, int color)
{
	img->data[y * (img->line_length / sizeof(int)) + x] = color;
}

__int8_t	find_texture(double ray_dir_x, double ray_dir_y, int side)
{
	if (side == 0)
		return (ray_dir_x <= 0);
	else
		return ((ray_dir_y <= 0) + 2);
	return (4);
}

void	calc_and_draw(t_data *info, int x)
{
	find_perp_wall(info);
	find_wall_x(info);
	draw_wall(info, x);
	draw_floor_ceiling(info, x, info->draw_start, info->draw_end);
}

void	draw_wall(t_data *info, int x)
{
	int	y;

	y = info->draw_start;
	while (y < info->draw_end)
	{
		info->tex_num = find_texture(info->ray_dir_x, info->ray_dir_y,
				info->side);
		info->tex_y = (int)info->tex_pos & (TEX_HEIGHT - 1);
		info->tex_pos += info->step;
		info->color = info->texture[info->tex_num][TEX_HEIGHT * info->tex_y
			+ info->tex_x];
		if (info->side == 1)
			info->color = (info->color >> 1) & 8355711;
		put_pixel_to_img(&info->mlx.map, x, y, info->color);
		y++;
	}
}
