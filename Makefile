# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/07/22 21:01:21 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SOURCE = main.c \
		 map.c \
		 move_up.c \
		 move_down.c \
		 move_left.c \
		 move_right.c \
		 numbers.c \
		 result.c \
		 window_init.c \

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) $(SOURCE) -o $(NAME) $(LIB) -lncurses 
	@echo "2048 compiled"

clean:
	@rm -rf *.o
	@make clean -C libft/
	@echo "objects cleaned"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@echo "all cleaned"

re: fclean all

gic:
	cp *.c ~/rush_2048
	cp header.h ~/rush_2048
	cp Makefile ~/rush_2048
