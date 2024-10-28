/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:04 by sumseo            #+#    #+#             */
/*   Updated: 2024/10/28 15:26:20 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ERROR_PARSING 0
# define ERROR_PARSING_MSG "Parsing"
# define ERROR_ARGUMENT_NB_MSG "Check argument number of the program."
# define SUCCESS 1
# define FAILURE 0
# define ALLOWED_CHARACTERS_SET "01NEWS"
# define STARTING_POS_SET "NEWS"
# define FORBIDDEN_CHARACTER -1
# define NO_STARTING_POS -2
# define MULTIPLE_STARTING_POS -3
# define MAP_NOT_CLOSED -4
# define MKO "Allocation failure."

// key events
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_KEY_EXIT 17

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_R 114
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// WINDOW AND IMAGE INFO
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 400
# define IMG_HEIGHT 300
#endif //__MACROS__H