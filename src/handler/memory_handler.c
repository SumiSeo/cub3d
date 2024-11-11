/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:43:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/11 15:43:20 by sokaraku         ###   ########.fr       */
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
		if (parsing_store->file)
			free_arrs((void **)parsing_store->file);
		if (parsing_store->rows_lens)
			free(parsing_store->rows_lens);
		free(parsing_store);
	}
}

/**
 * @brief Frees the mlx.
 * @param data A pointer to a structure.
 * @returns void.
 */
void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.map.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.minimap.img_ptr);
	free_textures(data->texture, 8);
	free_arrs((void **)data->mlx.parsing->file);
	free(data->mlx.parsing->rows_lens);
	free(data->mlx.parsing);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
}
