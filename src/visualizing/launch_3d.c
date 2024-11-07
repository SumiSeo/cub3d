/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/07 14:58:17 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_launch(t_data *data, t_parsing *parsing, t_screen *screen)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, "cub 3D");
	data->posX = parsing->posX;
	data->posY = parsing->posY;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->moveSpeed = 0.2;
	data->rotSpeed = 0.2;
	data->mlx.parsing = parsing;
	data->mlx.screen = screen;
	data->re_buf = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			data->buf[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (!(data->texture[i] = (int *)malloc(sizeof(int) * (texHeight
						* texWidth))))
			printf("Memory allocation failed for texture array");
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			data->texture[i][j] = 0;
		}
	}
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
	// (void)mlx;
}

int	map_loop(t_data *data)
{
	// **please keep this line for now ** minimap//
	// draw_squares(mlx);
	// draw_hero(mlx);
	// draw_lines(mlx);
	// draw_rays(mlx);
	// **please keep this line for now ** minimap//
	// mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win);
	ft_bzero(data->mlx.map.data, HEIGHT * WIDTH * sizeof(int));
	draw_rays(data);
	return (0);
}
void	load_image(t_mlx *mlx, int *texture, char *path)
{
	t_image	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &img.width,
			&img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	for (int y = 0; y < texHeight; y++)
	{
		for (int x = 0; x < texWidth; x++)
		{
			texture[texWidth * y + x] = img.data[texWidth * y + x];
		}
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

	// memory_handler(parsing, true);
	mlx_launch(&data, parsing, screen);
	/* img_launch function should be renamed */
	img_launch(&data.mlx);
	load_texture(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, &map_loop, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_PRESS, 1L << 0, &key_event, &data);
	mlx_hook(data.mlx.win, EVENT_KEY_EXIT, 0, &mlx_loop_end, data.mlx.mlx_ptr);
	mlx_loop(data.mlx.mlx_ptr);
	mlx_destroy_image(data.mlx.mlx_ptr, data.mlx.map.img_ptr);
	mlx_destroy_image(data.mlx.mlx_ptr, data.mlx.minimap.img_ptr);
	// free_arrs((void **)data.mlx.parsing->file);
	// free(data.mlx.parsing->rows_lens);
	// free(data.mlx.parsing);
	// mlx_destroy_window(data.mlx.mlx_ptr, data.mlx.win);
	// mlx_destroy_display(data.mlx.mlx_ptr);
	// free(data.mlx.mlx_ptr);
}
