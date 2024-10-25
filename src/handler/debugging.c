/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:28 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/25 14:22:20 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_screen(t_screen screen)
{
	printf("NORTH [%s]\n", screen.north);
	printf("SOUTH [%s]\n", screen.south);
	printf("EAST [%s]\n", screen.east);
	printf("WEST [%s]\n", screen.west);
	printf("FLOOR [%d]\n", screen.floor_color);
	printf("CEILING [%d]\n", screen.ceiling_color);
}