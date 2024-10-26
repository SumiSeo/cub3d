/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/26 20:18:30 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
void	param_init(t_key *key_params)
{
	key_params->x = 3;
	key_params->y = 4;
	key_params->str[0] = 'a';
	key_params->str[1] = 'b';
	key_params->str[2] = '\0';
}
int	key_press(int keycode, t_key *param)
{
	// static int	a = 0;
	printf("hello world\n");
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S) // Action when S key pressed
		param->x--;
	else if (keycode == KEY_ESC) // Quit the program when ESC key pressed
	{
		printf("he\n");
		exit(0);
	}
	printf("x: %d\n", param->x);
	return (0);
}
int	close_game(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

void	launch_game(t_parsing parsing)
{
	(void)parsing;

	int count_w;
	int count_h;

	t_image img;
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();

	mlx.win = mlx_new_window(mlx.mlx_ptr, 500, 500, "CUB 3D");
	// img.img_ptr = mlx_new_image(mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "./textures/cerisier.xpm",
			&img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);

	count_h = -1;
	while (++count_h < img.height)
	{
		count_w = -1;
		while (++count_w < img.width / 2)
		{
			if (count_w % 2)
				img.data[count_h * img.width + count_w] = 0xFFFFFF;
			else
				img.data[count_h * img.width + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 100, 100);
	mlx_hook(mlx.win, EVENT_KEY_EXIT, 0, &close_game, &mlx);
	mlx_loop(mlx.mlx_ptr);
}