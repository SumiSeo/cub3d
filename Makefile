NAME = cub3d

SRC_DIR = src
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR)/parsing

SRC_FILES = cub3d.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDES			=	-I inc
CC = cc 
CFLAGS = -Wall -Wextra -Werror
DEBUGGER = -g3



all : $(NAME)
$(NAME) : $(OBJ_DIR) $(OBJ) 
				@echo "\n"
				@echo "$(GREEN)Compiling...$(COLOR_END)"
				$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(DEBUGGER) -o $(NAME)
				@echo "$(LGREEN)project compiled !$(COLOR_END)"

$(OBJ_DIR) : 
			mkdir -p $@

$(OBJ_DIRS) : 
			mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIRS)
				$(CC) $(CFLAGS)$(INCLUDES) $(DEBUGGER) -c $< -o $@

clean : 
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -rf $(NAME)

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
