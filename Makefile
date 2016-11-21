#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 15:31:25 by abureau           #+#    #+#              #
#    Updated: 2016/11/21 15:31:25 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

SRC = ./src/atoibase.c \
	./src/beg.c \
	./src/builtin.c \
	./src/check_env.c \
	./src/echo.c \
	./src/echo_p.c \
	./src/env.c \
	./src/env_unset.c \
	./src/exec.c \
	./src/execute.c \
	./src/f_getenv.c \
	./src/fork.c \
	./src/free.c \
	./src/get_len.c \
	./src/get_next_line.c \
	./src/get_param.c \
	./src/gnl_patch.c \
	./src/init.c \
	./src/issymb.c \
	./src/main.c \
	./src/mod_cmd.c \
	./src/new_msh.c \
	./src/print.c \
	./src/run_echo.c \
	./src/run_env.c \
	./src/run_func.c \
	./src/secure_cat.c \
	./src/setenv_core.c \
	./src/setter.c

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
