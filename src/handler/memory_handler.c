/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:43:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/23 18:05:28 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	memory_handler(t_parsing *data, bool store)
{
	static t_parsing	*data_store;

	if (store)
	{
		data_store = data;
		return ;
	}
	if (data_store)
	{
		free_arrs((void **)data_store->file);
		free(data_store->rows_lens);
	}
}
