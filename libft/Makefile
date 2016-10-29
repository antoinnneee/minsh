#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:47:45 by abureau           #+#    #+#              #
#    Updated: 2016/02/24 14:51:20 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

DIRSRC = ./includes/

CC = gcc

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_counteradd.c \
		ft_counterdiv.c \
		ft_countermodul.c \
		ft_countereq.c \
		ft_counterset.c \
		ft_counterfree.c \
		ft_counterinit.c \
		ft_counterinitfunc.c \
		ft_countertab.c \
		ft_countermod.c \
		ft_countermul.c \
		ft_counterpow.c \
		ft_counterrecap.c\
		ft_inctwovar.c \
		ft_incdecvar.c \
		ft_incfourvar.c \
		ft_incthreevar.c \
		ft_inittwovar.c \
		ft_initfourvar.c \
		ft_initthreevar.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putnbrnl.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putstrnb.c \
		ft_square.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strtrimchar.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c

HEAD = ./includes/libft.h

OBJ = $(OBJS:%=$(DIRSRC)%)
OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
