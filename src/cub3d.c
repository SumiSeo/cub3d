/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/22 20:17:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(int argc, char **argv)
// {
// 	t_parsing	parsing;
// 	int			i = -1;
// 	parsing = init_pars(argv[1]);
// 	while (parsing.row_lens[++i] != -1)
// 	{
// 		printf("[%d] = %d\n", i, parsing.row_lens[i]);
// 	}
// 	if (argc == 2)
// 	{
// 		if (argc < 1)
// 			return (ERROR_PARSING);
// 		if (bg_parsing(argv[1]))
// 			print_err_msg(ERROR_PARSING_MSG, -1);
// 	}
// 	else
// 		return (printf("%s", ERROR_ARGUMENT_NB_MSG), (ERROR_PARSING));
// }
// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	t_parsing	parsing;
// 	// int			i = -1;
// 	parsing = init_pars(argv[1]);
// 	parse_map(&parsing);
// 	free(parsing.rows_lens);
// 	free_arrs((void **)parsing.file);
// }