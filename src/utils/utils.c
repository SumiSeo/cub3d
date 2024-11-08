/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/08 10:49:22 by sokaraku         ###   ########.fr       */
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
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	if (s1)
		new[i++] = c;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	return (new[i] = 0, free(s1), new);
}

/**
 * @brief Checks if a given character is in a given set.
 * @param c The character to check
 * @param set The set in which to find the character.
 * @returns True (1) if the character is in the given set
 * and false (0) otherwise.
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
 * @brief Finds the position of the player.
 * @param map A pointer to an array of strings containing the map.
 * @returns A structure containing the position of the player.
 */
void	find_player(char **map, double *pos_y, double *pos_x)
{
	short int	i;
	short int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_in_set(map[i][j], STARTING_POS_SET))
			{
				*pos_y = (double) i; 
				*pos_x = (double) j;
				return;
			}
		}
	}
}

/**
 * @brief Finds the maximum col inide the map
 * @param data A pointer to a structure containing informations about the file.
 * @returns The maximum col inside the map.
 */
short int	find_maximum_col(t_parsing *data)
{
	short int	maximum;
	int			i;

	maximum = data->rows_lens[0];
	i = 0;
	while (data->rows_lens[i] != -1)
	{
		if (maximum < data->rows_lens[i])
			maximum = data->rows_lens[i];
		i++;
	}
	return (maximum);
}

void	free_textures(int *textures[], __int8_t n)
{
	while (n--)
		free(textures[n]);
}