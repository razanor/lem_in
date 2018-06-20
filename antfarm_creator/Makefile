# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:34:33 by knovytsk          #+#    #+#              #
#    Updated: 2018/01/24 14:34:35 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = antfarm.creator

SRCS_PATH = srcs
OBJS_PATH = objs

SRCS = main.c links.c links2.c rooms.c rooms2.c win_init.c image.c hook.c draw_room.c \
	draw_line.c draw_links.c hook2.c run_lemin.c actions.c
OBJS = $(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
INCLUDES = -I includes
LIBINC = -I ./libft
LIBFT = ./libft/libft.a

CC = gcc -Wall -Wextra -Werror
FLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast -O3

all: $(NAME)

$(OBJS): | $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c
	@$(CC) -c $< $(INCLUDES) $(LIBINC) -o $@

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(FLAGS)
	@echo "\033[35;1mAnt creator\033[0m"

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@rm -rf bin objs

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all

vpath %.c $(SRCS_PATH)

.PHONY: clean fclean re all