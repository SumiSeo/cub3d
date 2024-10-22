/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/22 20:21:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief A simple strjoin, but it also puts a given character
 *  between the two strings to facilitate the split afterwards.
 * @param s1 A pointer to the first string to copy.
 * @param s2 a pointer to the second string to copy.
//  * @param c The char to put in the middle of s1 and s2.
 * @returns The merged strings, with a char c in the middle.
 * Returns NULL if the allocation failed or if the two strings are NULL.
 */
char	*merge_strings(char *s1, char *s2, char c)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	if (s1)
		new[i++] = c;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = 0;
	free(s1);
	return (new);
}

/**
 * @brief Checks if a given character is in a given set.
 * @param c The character to check
 * @param set The set in which to find the character.
 * @returns True (1) if the character is valid and false (0) otherwise.
 */
bool	is_in_set(char c, char *set)
{
	__int8_t	i;

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (true);
	}
	return (false);
}

/**
 * @brief
 * @param
 * @returns
 */
t_pos	find_player(char **map)
{
	short int	i;
	short int	j;
	t_pos		pos;

	i = -1;
	pos.y = -1;
	pos.x = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_in_set(map[i][j], STARTING_POS_SET))
			{
				pos.y = i;
				pos.x = j;
				return (pos);
			}
		}
	}
	return (pos);
}
