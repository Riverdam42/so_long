# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkawano <kkawano@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 14:23:27 by kkawano           #+#    #+#              #
#    Updated: 2021/10/07 14:33:38 by kkawano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INC = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
