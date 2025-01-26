# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 18:49:36 by mlaffita          #+#    #+#              #
#    Updated: 2025/01/26 18:51:15 by mlaffita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRCDIR = .
OBJDIR = $(SRCDIR)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

SRC_CLIENT =	client.c
SRC_SERVER =	server.c

OBJS_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJS_SERVER = $(SRC_SERVER:%.c=%.o)

CC = gcc

INCLUDE = -I include

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER) 

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) all -C $(PRINTFDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

clean:
		$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) 
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)
fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)
		$(MAKE) fclean -C $(LIBFTDIR)
		$(MAKE) fclean -C $(PRINTFDIR)

re: fclean all

.PHONY: all clean fclean re