/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 19:59:40 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dir_plane(t_data *data, char direction)
{
	data->dir_y = 0;
	data->dir_x = 0;
	data->plane_x = 0;
	data->plane_y = 0;
	if (direction == 'N')
	{
		data->dir_y = -1;
		data->plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		data->dir_y = 1;
		data->plane_x = -0.66;
	}
	else if (direction == 'W')
	{
		data->dir_x = -1;
		data->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		data->dir_x = 1;
		data->plane_y = 0.66;
	}
}

int	map_loop(t_data *data)
{
	ft_bzero(data->mlx.map.data, HEIGHT * WIDTH * sizeof(int));
	draw_rays(data);
	return (0);
}

void	load_image(t_mlx *mlx, int *texture, char *path)
{
	t_image	img;
	int		y;
	int		x;

	img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &img.width,
			&img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = 0;
	while (y < TEX_HEIGHT)
	{
		x = 0;
		while (x < TEX_WIDTH)
		{
			texture[TEX_WIDTH * y + x] = img.data[TEX_WIDTH * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
}

void	load_texture(t_data *info)
{
	load_image(&info->mlx, info->texture[0], "textures/barrel.xpm");
	load_image(&info->mlx, info->texture[1], "textures/redbrick.xpm");
	load_image(&info->mlx, info->texture[2], "textures/purplestone.xpm");
	load_image(&info->mlx, info->texture[3], "textures/greystone.xpm");
	load_image(&info->mlx, info->texture[4], "textures/bluestone.xpm");
	load_image(&info->mlx, info->texture[5], "textures/mossy.xpm");
	load_image(&info->mlx, info->texture[6], "textures/wood.xpm");
	load_image(&info->mlx, info->texture[7], "textures/colorstone.xpm");
}

void	launch_game(t_parsing *parsing, t_screen *screen)
{
	t_data	data;

	memory_handler(parsing, true);
	mlx_launch(&data, parsing, screen);
	img_launch(&data.mlx);
	load_texture(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, &map_loop, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_PRESS, 1L << 0, &key_event, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_EXIT, 0, &mlx_loop_end, data.mlx.mlx_ptr);
	mlx_loop(data.mlx.mlx_ptr);
	mlx_destroy_image(data.mlx.mlx_ptr, data.mlx.map.img_ptr);
	mlx_destroy_image(data.mlx.mlx_ptr, data.mlx.minimap.img_ptr);
	free_textures(data.texture, 8);
	free_arrs((void **)data.mlx.parsing->file);
	free(data.mlx.parsing->rows_lens);
	free(data.mlx.parsing);
	mlx_destroy_window(data.mlx.mlx_ptr, data.mlx.win);
	mlx_destroy_display(data.mlx.mlx_ptr);
	free(data.mlx.mlx_ptr);
}
