# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 14:15:51 by knovytsk          #+#    #+#              #
#    Updated: 2017/11/03 10:13:53 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
		ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
		ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstback.c \
		ft_lstcount.c ft_lstsize.c ft_sort.c ft_strrev.c ft_swap.c get_next_line.c \
		ft_atoi_hex.c free_array.c ft_issign.c\
		ft_printf.c arg_analize.c format_analize.c analizers.c check_float.c check_format.c\
		reset_initial.c char_conversions.c integer_conversions.c other_conversions.c\
		float_conversions.c time_conversion.c non_printable_conversion.c a_conv_operations.c\
		g_conv_operations.c for_int_conv.c for_wide_char.c for_f_conv.c for_e_conv.c\
		for_g_conv.c for_a_conv.c double_sizes.c width_precision.c manage_operations.c\
		modifiers.c flags_operations.c apostr_production.c put_marks.c has_char.c check_array_num.c \
		find_pos.c count_spaces.c print_tab.c create_tab.c error_exit.c
FLAGS = gcc -Wall -Wextra -Werror -c -I
OBJECTS = $(SRCS:.c=.o)
INCLUDES = libft.h

all: $(NAME)

%.o: %.c
	@$(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)  
	@ar rc $(NAME) $(OBJECTS)
	
clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
