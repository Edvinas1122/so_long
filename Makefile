# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 06:40:44 by emomkus           #+#    #+#              #
#    Updated: 2022/01/25 17:03:28 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
SRC_FILES = main.c
SRC_DIR = src/
OBJ = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))
#---ENGINE-----------------------
ENGINE_FILES = map_scan.c
ENGINE_OBJ = $(ENGINE_FILES:.c=.o)
ENGINE_DIR = src/engine/
ENGINE = $(addprefix $(ENGINE_DIR),$(ENGINE_FILES))
#---Libraries---------------------
PRINTF_FILES = printf.h libftprintf.a
PRINTF_DIR = src/lib/printf/
PRINTF = $(addprefix $(PRINTF_DIR),$(PRINTF_FILES))
GNL_FILES = get_next_line.h get_line.a
GNL_DIR = src/lib/GNL/
GNL = $(addprefix $(GNL_DIR),$(GNL_FILES))
LIBFT_FILES = libft.h libft.a
LIBFT_DIR = src/lib/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))
#---Flags-------------------------
FLAGS = -g -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
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

$(NAME): $(OBJ) $(ENGINE_OBJ) $(PRINTF) $(LIBFT) $(GNL)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(LINKS) $(OBJ) $(ENGINE_OBJ) $(LIB) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@rm $(ENGINE_OBJ)
	@echo $(CURSIVE) $(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC) 
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

$(ENGINE_OBJ): $(ENGINE)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(ENGINE)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBTF_DIR)

$(GNL):
	make -C $(GNL_DIR)

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

re: fclean all