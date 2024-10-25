/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/25 15:26:30 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extension(char *file)
{
	char	*str;

	str = ft_strnstr(file, ".cub", ft_strlen(file));
	if (!str)
		return (false);
	if (ft_strlen(str) > 4)
		return (false);
	if (str == file)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_parsing parsing;
	t_screen screen;
	// int			i = -1;
	if (check_extension(argv[1]) == FAILURE)
		print_err_msg("Invalid file extension", -1);

	parsing = init_pars(argv[1]);
	ft_memset(&screen, 0, sizeof(t_screen));
	if (bg_parsing(parsing, screen))
		print_err_msg(ERROR_PARSING_MSG, -1);
	launch_game(parsing);

	memory_handler(&parsing, true);
	parse_map(&parsing);
	free(parsing.rows_lens);
	free_arrs((void **)parsing.file);
}