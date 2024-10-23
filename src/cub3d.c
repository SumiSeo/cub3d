/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/23 18:00:57 by sokaraku         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	(void)argc;
	t_parsing	parsing;
	// int			i = -1;
	if (check_extension(argv[1]) == FAILURE)
		print_err_msg("Invalid file extension", -1);
	parsing = init_pars(argv[1]);
	memory_handler(&parsing, true);
	parse_map(&parsing);
	free(parsing.rows_lens);
	free_arrs((void **)parsing.file);
}