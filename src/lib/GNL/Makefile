# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 11:23:08 by emomkus           #+#    #+#              #
#    Updated: 2022/01/25 11:27:41 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_line.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(BONUSOFILES)

fclean:
	rm -f $(OBJ)
	rm -f $(BONUSOFILES)
	rm -f $(NAME)

re:		fclean all

%.o: %.c
	gcc $(FLAG) -c $^ -o $@

.PHONY:			all clean fclean