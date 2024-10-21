/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/10/21 20:32:12 by sokaraku         ###   ########.fr       */
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
 * @brief Checks if a given char is present in a string.
 * @param str The string to check.
 * @param c The char to find.
 * @returns True (1) if the char is found and false (0) otherwise.
 */
bool	find_char(char *str, char c)
{
	short int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (true);
	}
	return (false);
}
