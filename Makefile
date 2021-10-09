# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkawano <kkawano@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 14:23:27 by kkawano           #+#    #+#              #
#    Updated: 2021/10/07 14:37:08 by kkawano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INC = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME: $(OBJS)
	$(CC) -Lmlx -lmlx -franework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
