/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:41:04 by sumseo            #+#    #+#             */
/*   Updated: 2024/11/11 12:30:32 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// PARSING
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

// KEY EVENTS
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_KEY_EXIT 17

# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100
# define KEY_LOOK_RIGHT 65363
# define KEY_LOOK_LEFT 65361

// WINDOW AND IMAGE INFO
# define WIN_ 800
# define WIN_HEIGHT 600
# define IMG_WIDTH 400
# define IMG_HEIGHT 300

# define TILE_SIZE 50
# define ROWS 20
# define COLS 50
# define WIDTH 640
# define HEIGHT 400
# define TEX_HEIGHT 64
# define TEX_WIDTH 64

// MAP_INDEX

# define WEST 0
# define EAST 1
# define NORTH 2
# define SOUTH 3
#endif //__MACROS__H