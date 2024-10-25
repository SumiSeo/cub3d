/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:49:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/25 15:28:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints an error message, close a file descriptor if needed,
 * frees allocated memory and exits the program.
 * @param msg The message to print.
 * @param fd  A file descriptor.
 * @returns void.
 */
void	print_err_msg(char *msg, int fd)
{
	if (fd >= 0)
		close(fd);
	memory_handler(NULL, 0);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
