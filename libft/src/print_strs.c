/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:02:19 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/21 17:28:39 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	print_strs(char **strs, char new_line)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		if (new_line)
			ft_putendl_fd(strs[i], STDOUT_FILENO);
		else
			ft_putstr_fd(strs[i], STDOUT_FILENO);
	}
}
