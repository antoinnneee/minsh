#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 18:10:11 by abureau           #+#    #+#              #
#    Updated: 2016/11/10 18:10:11 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minish

SRC = ./src/echo_p.c \
	./src/beg.c \
	./src/env.c \
	./src/echo.c \
	./src/builtin.c \
	./src/run_func.c \
	./src/secure_cat.c \
	./src/execute.c \
	./src/get_param.c \
	./src/f_getenv.c \
	./src/main.c \
	./src/init.c \
	./src/free.c \
	./src/get_next_line.c \
	./src/exec.c \
	./src/gnl_patch.c \
	./src/atoibase.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

all: LIBCOMPILE $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft

LIBCOMPILE:
	 make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
