# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 04:49:40 by briveiro          #+#    #+#              #
#    Updated: 2023/01/26 03:21:01 by briveiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex


SRC = childs.c error.c free.c main.c path.c \
		split.c struct.c utilis.c

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

OBJS = $(SRC:.c=.o)



all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@gcc $(CCFLAGS) $(OBJS) -o $(NAME)
	@echo "Se ha compilado perfectamente ✅"

clean:
	@rm -f $(OBJS)
	@echo "Se ha borrado todo :D"


fclean: clean
	@rm -f $(NAME)

	
re: fclean all

.PHONY: all fclean clean re
