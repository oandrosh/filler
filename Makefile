# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 06:23:10 by oandrosh          #+#    #+#              #
#    Updated: 2019/02/21 06:36:06 by oandrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = oandrosh.filler

FLAGS = -Wall -Werror -Wextra

SRC = source/map_figure.c source/filler.c source/find_place.c

OBJ = $(SRC:%.c=%.o) 

all: $(NAME)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	@make -C lib
	@gcc $(OBJ) lib/libftprintf.a -o $(NAME)

clean: 
	@make clean -C lib
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib
	@rm -f $(NAME)

re: fclean all
