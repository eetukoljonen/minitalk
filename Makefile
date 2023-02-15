# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:36:49 by ekoljone          #+#    #+#              #
#    Updated: 2023/02/13 13:27:50 by ekoljone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
SRCS = server.c client.c
OBJ = $(SRCS:.c=.o)
LIBFT = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: server client

server: server.o
	@make -s -C $(LIBFT)
	$(CC) -o $@ $< $(LIBFT)/libft.a

client: client.o
	@make -s -C libft
	$(CC) -o $@ $< $(LIBFT)/libft.a

clean:
	rm -f $(OBJ)
	@make clean -s -C $(LIBFT)

fclean: clean
	rm -f server client
	@make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: all bonus libft clean fclean re