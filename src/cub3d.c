/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/01 14:52:54 by sumseo           ###   ########.fr       */
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
	t_parsing *parsing;
	t_screen *screen;

	if (check_extension(argv[1]) == FAILURE)
		print_and_exit("Wrong extension. Allowed extension is .cub");
	parsing = init_pars_struct(argv[1]);
	screen = malloc(sizeof(t_screen));
	parse_map(parsing);
	ft_memset(screen, 0, sizeof(t_screen));
	printf("parsing file %s\b", parsing->file[0]);
	if (bg_parsing(parsing, screen))
		print_err_msg(ERROR_PARSING_MSG, -1);
	launch_game(parsing, screen);
	// call();
	memory_handler(parsing, true);
	free(parsing->rows_lens);
	free_arrs((void **)parsing->file);
	free(parsing);
}