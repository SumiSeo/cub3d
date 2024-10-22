/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:42 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/22 18:29:40 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	launch_game(t_parsing parsing)
{
	(void)parsing;
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();

	while (42)
	{
		// printf("hello world \n");
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		mlx_loop(mlx);
	}
}