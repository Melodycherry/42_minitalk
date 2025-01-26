# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 18:49:36 by mlaffita          #+#    #+#              #
#    Updated: 2025/01/26 18:50:10 by mlaffita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = .
OBJDIR = $(SRCDIR)

SRC =	ft_printf.c \
		ft_number.c \
		ft_pointer.c \
		ft_hexa.c \
		ft_unsigned_int.c \
		ft_putchar_len.c \
		ft_string.c \

OBJS = $(SRC:%.c=%.o)

# Header file directory
INCLUDES = -I ../include

CC = gcc

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(RM) $(OBJS) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re