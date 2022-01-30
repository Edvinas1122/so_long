# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 06:40:44 by emomkus           #+#    #+#              #
#    Updated: 2022/01/30 04:08:35 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
#---ENGINE-----------------------
ENGINE_FILES = initialize.c map_to_heap.c key_to_heap_map.c display.c
ENGINE_OBJ = $(ENGINE_FILES:.c=.o)
ENGINE_DIR = src/engine/
ENGINE = $(addprefix $(ENGINE_DIR),$(ENGINE_FILES))
#---Libraries---------------------
PRINTF_FILES = ft_printf.h libftprintf.a
# PRINTF_FILES = libftprintf.a
PRINTF_DIR = src/lib/printf/
PRINTF = $(addprefix $(PRINTF_DIR),$(PRINTF_FILES))
GNL_FILES = get_next_line.h get_line.a
#GNL_FILES = get_line.a
GNL_DIR = src/lib/GNL/
GNL = $(addprefix $(GNL_DIR),$(GNL_FILES))
LIBFT_FILES = libft.h libft.a
#LIBFT_FILES = libft.a
LIBFT_DIR = src/lib/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))
#---Flags-------------------------
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
#---Colors------------------------
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

OS:= $(shell uname -s)
ifeq ($(OS),Darwin)
	SRC_FILES = main_iMac.c
	MLX_FILES = libmlx.a
	MLX_DIR = src/lib/mlx_Darwin/
	MLX = $(addprefix $(MLX_DIR),$(MLX_FILES))
	LINKS_OBJ = -I$(MLX_DIR)
	LINKS = -L$(MLX_DIR) -framework OpenGL -framework AppKit
	KEY = -D KEY_A=0 -D KEY_W=13 -D KEY_D=2 -D KEY_S=1 -D KEY_ESC=53 -D SPEED=13
	CFLAG = -I
endif

ifeq ($(OS),Linux)
	SRC_FILES = main.c
	MLX_FILES = libmlx_linux.a
	MLX_DIR = src/lib/mlx/
	MLX = $(addprefix $(MLX_DIR),$(MLX_FILES))
	X11 = /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXext.so
	LINKS = -Isrc/lib/mlx -lX11 -lXext -lm  -L/usr/include/X11
endif

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ = $(SRC_FILES:.c=.o)

LIB = $(CFLAG) $(PRINTF) $(CFLAG) $(LIBFT) $(CFLAG) $(GNL)

all: $(NAME)

$(NAME): $(OBJ) $(ENGINE_OBJ) $(PRINTF) $(LIBFT) $(GNL) $(MLX)
	@echo $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	gcc $(FLAGS) $(LINKS) $(OBJ) $(ENGINE_OBJ) $(MLX) $(LIB) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ) $(ENGINE_OBJ)

$(OBJ): $(SRC)
	@echo $(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) $(LINKS_2) -c $(SRC)

$(ENGINE_OBJ): $(ENGINE)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) $(KEY) $(LINKS_OBJ) -c $(ENGINE)

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