# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 14:23:27 by kkawano           #+#    #+#              #
#    Updated: 2021/11/06 20:32:53 by kkawano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	main.c\
		main_utils.c\
		ft_read_map.c\
		ft_check_map.c\
		ft_init_data.c\
		ft_draw_map.c\
		ft_key_hook.c\
		ft_close_map.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

INC = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
