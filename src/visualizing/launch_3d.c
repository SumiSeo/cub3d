/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/28 12:32:24 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TILE_SIZE 32
#define ROWS 11
#define COLS 15
#define WIDTH COLS *TILE_SIZE
#define HEIGHT ROWS *TILE_SIZE

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
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
	{
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
void	mlx_launch(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "cub 3D");
}

void	img_launch(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}

void	draw_square(t_mlx *mlx, int x, int y)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	j = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx->img.data[(y + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_squares(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (mlx->parsing->map[i][j] == '1')
				draw_square(mlx, j, i);
			j++;
		}
		i++;
	}
}
int	img_loop(t_mlx *mlx)
{
	draw_squares(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}
void	launch_game(t_parsing *parsing)
{
	t_mlx mlx;

	ft_memset(&mlx, 0, sizeof(mlx));
	mlx.parsing = parsing;
	mlx_launch(&mlx);
	img_launch(&mlx);
	mlx_hook(mlx.win, EVENT_KEY_EXIT, 0, &close_game, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &img_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
}