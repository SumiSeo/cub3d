/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:57:58 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 21:43:30 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	launch_texture(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		data->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT
					* TEX_WIDTH));
		if (!data->texture[i])
			printf("Memory allocation failed for texture array");
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			data->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	mlx_launch(t_data *data, t_parsing *parsing, t_screen *screen)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, "cub 3D");
	data->pos_x = parsing->pos_x;
	data->pos_y = parsing->pos_y;
	set_dir_plane(data, parsing->map[(int)parsing->pos_y][(int)parsing->pos_x]);
	data->move_speed = 0.1;
	data->rot_speed = 0.2;
	data->mlx.parsing = parsing;
	data->mlx.screen = screen;
	launch_texture(data);
}

void	img_launch(t_mlx *mlx)
{
	mlx->minimap.img_ptr = mlx_new_image(mlx->mlx_ptr, MINIMAP_WIDTH,
			MINIMAP_HEIGHT);
	mlx->minimap.data = (int *)mlx_get_data_addr(mlx->minimap.img_ptr,
			&mlx->minimap.bits_per_pixel, &mlx->minimap.line_length,
			&mlx->minimap.endian);
	mlx->map.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->map.data = (int *)mlx_get_data_addr(mlx->map.img_ptr,
			&mlx->map.bits_per_pixel, &mlx->map.line_length, &mlx->map.endian);
	ft_bzero(mlx->map.data, WIDTH * HEIGHT * sizeof(int));
}

void	init_side(t_data *info)
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
	init_side(info);
}
