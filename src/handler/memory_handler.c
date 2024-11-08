/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:43:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/08 15:29:34 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Stores locally any malloc'd data to be able to free it globally.
 * @param parsing A pointer to a structure containing informations
 * about the file.
 * @param store A boolean taking the value 1 if you only need to store any
 * malloc'd data and 0 if data needs to be freed.
 * @returns void.
 */
void	memory_handler(t_parsing *parsing, bool store)
{
	static t_parsing	*parsing_store;

	if (store)
	{
		parsing_store = parsing;
		return ;
	}
	if (parsing_store)
	{
		free_arrs((void **)parsing_store->file);
		if (parsing_store->rows_lens)
			free(parsing_store->rows_lens);
		free(parsing_store);
	}
}
