# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 06:40:44 by emomkus           #+#    #+#              #
#    Updated: 2022/01/29 21:13:08 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
SRC_FILES = main.c
SRC_DIR = src/
OBJ = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))
SRC_FILES_IMAC = main_iMac.c
SRC_DIR_IMAC = src/
OBJ_IMAC = $(SRC_FILES_IMAC:.c=.o)
SRC_IMAC = $(addprefix $(SRC_DIR_IMAC),$(SRC_FILES_IMAC))
#---ENGINE-----------------------
ENGINE_FILES = initialize.c map_to_heap.c key_to_heap_map.c display.c
ENGINE_OBJ = $(ENGINE_FILES:.c=.o)
ENGINE_DIR = src/engine/
ENGINE = $(addprefix $(ENGINE_DIR),$(ENGINE_FILES))
#---Libraries---------------------
PRINTF_FILES = ft_printf.h libftprintf.a
PRINTF_DIR = src/lib/printf/
PRINTF = $(addprefix $(PRINTF_DIR),$(PRINTF_FILES))
GNL_FILES = get_next_line.h get_line.a
GNL_DIR = src/lib/GNL/
GNL = $(addprefix $(GNL_DIR),$(GNL_FILES))
LIBFT_FILES = libft.h libft.a
LIBFT_DIR = src/lib/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))
MLX_FILES = mlx.h libmlx.a
MLX_DIR = src/lib/mlx/
MLX = $(addprefix $(MLX_DIR),$(MLX_FILES))
#---Flags-------------------------
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
LINKS = -lmlx -framework OpenGL -framework AppKit
LINKS_2 = -L src/lib/mlx -L /usr/X11/lib -lX11 -lXext -Imlx -lmlx
IMAC = -D KEY_A=0 -D KEY_W=13 -D KEY_D=2 -D KEY_S=1 -D KEY_ESC=53 -D SPEED=13
#---Colors------------------------
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

OS:= $(shell uname -s)
ifeq ($(OS),Darwin)
	CFLAG = -I
endif

LIB = $(CFLAG) $(PRINTF) $(CFLAG) $(LIBFT) $(CFLAG) $(GNL)

all: $(NAME)

$(NAME): $(OBJ) $(ENGINE_OBJ) $(PRINTF) $(LIBFT) $(GNL) $(MLX)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(LINKS_2) $(OBJ) $(ENGINE_OBJ) $(LIB) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@rm $(ENGINE_OBJ)
	@echo $(CURSIVE) $(GRAY) "     Deleted object files" $(NONE)

iMac: $(PRINTF) $(LIBFT) $(GNL) $(OBJ_IMAC) 
	gcc $(FLAGS) $(IMAC) -c $(SRC_IMAC) $(ENGINE)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	gcc $(FLAGS) $(IMAC) $(LINKS) $(OBJ_IMAC) $(ENGINE_OBJ) $(LIB) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ_IMAC)
	@rm $(ENGINE_OBJ)
	@echo $(CURSIVE) $(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC) 
	@echo $(CURSIVE)$(GRAY) "     - Making iMac object files..." $(NONE)
	@gcc $(FLAGS) -D SYS=42 -c $(SRC)

$(OBJ_IMAC): $(SRC_IMAC) 
	@echo $(CURSIVE)$(GRAY) "     - Making iMac object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC_IMAC)

$(ENGINE_OBJ): $(ENGINE)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(ENGINE)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(MLX):
	make -C $(MLX_DIR)

quick:
	gcc $(FLAGS) $(LINKS) $(SRC) $(ENGINE) $(LIB) $(NAME)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@rm -rf $(ENGINE_OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	
re: fclean all