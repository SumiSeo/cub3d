/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/22 16:53:49 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	t_screen	screen;

	if (argc == 2)
	{
		if (argc < 1)
			return (ERROR_PARSING);
		parsing = init_pars(argv[1]);
		ft_memset(&screen, 0, sizeof(t_screen));
		if (bg_parsing(parsing, screen))
			print_err_msg(ERROR_PARSING_MSG, -1);
		launch_game(parsing);
	}
	else
		return (printf("%s", ERROR_ARGUMENT_NB_MSG), (ERROR_PARSING));
}
