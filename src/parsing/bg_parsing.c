/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/21 16:11:05 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bg_parsing(char *argv)
{
	int fd;
	char *line;
	fd = open(argv, O_RDONLY);
	if (fd > 0)
	{
		printf("This is arugment %s\n", argv);
		get_next_line(fd, 0);
		return (0);
	}
	else
	{
		return (1);
	}
}