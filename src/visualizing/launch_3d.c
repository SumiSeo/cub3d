/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/11 15:35:31 by sokaraku         ###   ########.fr       */
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

bool	load_image(t_mlx *mlx, int *texture, char *path)
{
	t_image	img;
	int		y;
	int		x;

	img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &img.width,
			&img.height);
	if (!img.img_ptr)
		return (FAILURE);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (!img.img_ptr)
		return (false);
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
	return (SUCCESS);
}

void	load_texture(t_data *info)
{
	char		**file;
	__int8_t	i;
	bool		ret;

	file = info->mlx.parsing->file;
	i = 0;
	while (i < info->mlx.parsing->map_beginning - 2)
	{
		if (file[i][0] == 'N')
			ret = load_image(&info->mlx, info->texture[NORTH], &file[i][3]);
		else if (file[i][0] == 'E')
			ret = load_image(&info->mlx, info->texture[EAST], &file[i][3]);
		else if (file[i][0] == 'S')
			ret = load_image(&info->mlx, info->texture[SOUTH], &file[i][3]);
		else if (file[i][0] == 'W')
			ret = load_image(&info->mlx, info->texture[WEST], &file[i][3]);
		i++;
		if (ret == FAILURE)
		{
			free_mlx(info);
			print_and_exit("Issue while loading an image");
		}
	}
}

void	launch_game(t_parsing *parsing, t_screen *screen)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	memory_handler(parsing, true);
	mlx_launch(&data, parsing, screen);
	img_launch(&data.mlx);
	load_texture(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, &map_loop, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_PRESS, 1L << 0, &key_event, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_EXIT, 0, &mlx_loop_end, data.mlx.mlx_ptr);
	mlx_loop(data.mlx.mlx_ptr);
	free_mlx(&data);
}
