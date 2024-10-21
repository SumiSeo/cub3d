/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:32:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/21 17:51:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// CAREFUL of ft_error : first free memory and then call it

char	**create_map(int fd)
{
	char	*tmp;
	char	*gnl;
	char	**map;

	gnl = get_next_line(fd, 0);
	if (!gnl)
		return (print_err_msg(MKO), NULL);
	tmp = NULL;
	while (gnl)
	{
		tmp = merge_strings(tmp, gnl, -32);
		if (!tmp)
			return (print_err_msg(MKO), get_next_line (fd, 1), NULL);
		gnl = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	map = ft_split(tmp, -32);
	free(tmp);
	if (!map)
		return (print_err_msg(MKO), get_next_line (fd, 1), NULL);
	return (map);
}

// bool	check_empty_space(char **map)
// {
// 	short int	i;
// 	short int	j;

// 	i = -1;
// 	j = -1;
// }