NAME = cub3D

SRC_DIR = src
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR)/parsing $(OBJ_DIR)/handler $(OBJ_DIR)/utils $(OBJ_DIR)/visualizing

SRC_FILES = cub3d.c parsing/bg_parsing.c handler/error_handler.c parsing/check_map.c \
			parsing/create_map.c utils/utils.c visualizing/launch_3d.c handler/memory_handler.c \
			parsing/parse_map.c parsing/is_closed_map.c handler/debugging.c \
			parsing/color_parsing.c visualizing/key_handling.c \
			visualizing/drawing_map.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDES = -I inc -I libft/includes -I minilibx-linux

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
DEBUGGER = -g3

LIBFT_DIR	= libft
LIBFT_LIB	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_LIB))

MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = libmlx.a
MINILIBX = $(addprefix $(MINILIBX_DIR)/, $(MINILIBX_LIB))

all : $(NAME)

$(LIBFT) :
			@echo "$(YELLOW)Compiling libft...$(COLOR_END)"
			make -s -C libft
			@echo "$(YELLOW)libft compiled !$(COLOR_END)"
$(MINILIBX) : 
			@echo "$(BLUE)Compiling minilibx...$(COLOR_END)"
			make -s -C minilibx-linux
			@echo "$(BLUE)minilibx compiled !$(COLOR_END)"

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(MINILIBX)
		@echo "\n"
		@echo "$(PURPLE)Compiling project...$(COLOR_END)"
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MINILIBX) $(DEBUGGER) -o $(NAME) -Lminilibx-linux -lmlx -lm -lX11 -lXext
		@echo "$(PURPLE)Project compiled!$(COLOR_END)"


$(OBJ_DIR) : 
			mkdir -p $@

$(OBJ_DIRS) : 
			mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIRS)
				$(CC) $(CFLAGS) $(INCLUDES) $(DEBUGGER) -Iminilibx_linux -c $< -o $@


clean : 
		rm -rf $(OBJ_DIR) 
fclean : clean
		rm -rf $(NAME) $(LIBFT) $(MINILIBX)
		make -C libft fclean
		make -C minilibx-linux clean
		@if test -f "maps/output.txt"; then rm maps/output.txt; fi

re : fclean all

test : $(NAME)
		(cd maps; ./test.sh)

.PHONY : all clean fclean re test


LGREEN				=	\033[1;32m
GREEN				=	\033[32m

LBLUE				=	\033[1;34m
BLUE				=	\033[34m

PURPLE 				= \033[0;35m

RED					=	\033[31m

LYELLOW				=	\033[1;33m
YELLOW				=	\033[33m

COLOR_END			=	\033[0m

FACE_ESCUZME		=	🤓