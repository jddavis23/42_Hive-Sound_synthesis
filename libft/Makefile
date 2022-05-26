# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:19:40 by jdavis            #+#    #+#              #
#    Updated: 2022/05/16 10:39:16 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = libft/

CC = gcc -Wall -Wextra -Werror -I libft/

SRC = solve_c_s_p.c
SRC += ft_printf.c
SRC += flags_plus.c
SRC += char_digit.c
SRC += num_to_ascii.c
SRC += num_to_ascii_2.c
SRC += num_to_ascii_3.c
SRC += num_to_ascii_4.c
SRC += solve_num.c
SRC += collect.c
SRC += choice.c
SRC += create_struct.c
SRC += rounder.c
SRC += and_or_type.c
SRC += width_num.c
SRC += ft_atolli.c
SRC += ft_numb_count.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) -c -I ./includes $(SRC)
	@ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
