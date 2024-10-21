/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:12:55 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/21 20:30:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argc < 1)
			return (ERROR_PARSING);
		if (bg_parsing(argv[1]))
			return (print_err_msg(ERROR_PARSING_MSG));
	}
	else
		return (printf("%s", ERROR_ARGUMENT_NB_MSG), (ERROR_PARSING));
}
