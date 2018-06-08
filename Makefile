# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrepak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 13:06:12 by nrepak            #+#    #+#              #
#    Updated: 2018/03/20 13:06:15 by nrepak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
LIB = libftprintf.a
SRC = lem_in.c auxiliary.c validation.c deep_validation.c data_collection.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@ echo "-----------------------------------"
	@ echo "lem-in is ready to work"
	@ cd ./libft && make && mv $(LIB) ..
	@ gcc $(OBJ) $(LIB) $(FLAGS) -o $(NAME)
%.o: %.c
	@ gcc $(FLAGS) -c $<
clean:
	@ echo "-----------------------------------"
	@ echo "Objects files are removed"
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean
fclean: clean
	@ echo "-----------------------------------"
	@ echo "lem-in is deleted"
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ cd ./libft && make fclean
re: fclean all
