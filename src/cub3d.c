/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/09 17:47:46 by sumseo           ###   ########.fr       */
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
	t_parsing	*parsing;
	t_screen	screen;
	(void)argc;
	
	if (check_extension(argv[1]) == FAILURE)
		print_and_exit("Wrong extension. Allowed extension is .cub");
	parsing = init_pars_struct(argv[1]);
	parse_map(parsing);
	ft_memset(&screen, 0, sizeof(t_screen));
	if (bg_parsing(parsing, &screen))
		print_err_msg(ERROR_PARSING_MSG, -1);
	launch_game(parsing, &screen);
}
