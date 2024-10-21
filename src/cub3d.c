/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/21 17:29:17 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		if (argc < 1)
// 			return (ERROR_PARSING);
// 		if (bg_parsing(argv[1]))
// 			return (print_err_msg(ERROR_PARSING_MSG));
// 	}
// 	else
// 		return (printf("%s", ERROR_ARGUMENT_NB_MSG), (ERROR_PARSING));
// }

int main(int argc, char **argv)
{
	(void)argc;

	int fd = open(argv[1], O_RDONLY);
	char **map = create_map(fd);
	if (!map)
		return (127);
	print_strs(map, 0);
	free_arrs((void **)map);
}