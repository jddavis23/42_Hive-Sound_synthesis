# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:50:46 by jdavis            #+#    #+#              #
#    Updated: 2022/05/26 17:05:23 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minisynth
SRC = main.c waves.c sound.c
OBJS = $(SRC:.c=.o)
CFLAGS = -I/Users/acamaras/.brew/include/SDL2 -D_THREAD_SAFE 
LIB = -L/Users/acamaras/.brew/lib -lSDL2 -L. libft/libftprintf.a


.PHONY: all clean fclean re

all: libftprinta $(NAME)

libftprinta:
	make -C libft/ re

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(LIB) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(LIB) -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
