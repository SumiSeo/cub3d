NAME = cub3D

SRC_DIR = src
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR)/parsing $(OBJ_DIR)/handler $(OBJ_DIR)/utils $(OBJ_DIR)/visualizing

SRC_FILES = cub3d.c parsing/bg_parsing.c handler/error_handler.c parsing/check_map.c \
			parsing/create_map.c utils/utils.c visualizing/launch_3d.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDES			=	-I inc -I libft/includes
CC = cc 
CFLAGS = -Wall -Wextra -Werror #  -L./minilibx-linux -lmlx
DEBUGGER = -g3

LIBFT_DIR	= libft
LIBFT_LIB	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_LIB))

MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = minilibx.a
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
	
$(NAME) : $(OBJ_DIR) $(OBJ) $(LIBFT) $(MINILIBX)
				@echo "\n"
				@echo "$(GREEN)Compiling project...$(COLOR_END)"
				$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(DEBUGGER) -o $(NAME)
				@echo "$(LGREEN)project compiled !$(COLOR_END)"

$(OBJ_DIR) : 
			mkdir -p $@

$(OBJ_DIRS) : 
			mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIRS)
				$(CC) $(CFLAGS) $(INCLUDES) $(DEBUGGER) -c $< -o $@

clean : 
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -rf $(NAME)
		make -C libft fclean

re : fclean all

.PHONY : all clean fclean re 


LGREEN				=	\033[1;32m
GREEN				=	\033[32m

LBLUE				=	\033[1;34m
BLUE				=	\033[34m

RED					=	\033[31m

LYELLOW				=	\033[1;33m
YELLOW				=	\033[33m

COLOR_END			=	\033[0m

FACE_ESCUZME		=	🤓
