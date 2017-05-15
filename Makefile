# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 12:58:46 by tjose             #+#    #+#              #
#    Updated: 2017/05/14 21:25:09 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
CC = gcc
CFLAGS =
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))
SRCFILES = main.c \
		   lem_in_atoi.c \
		   get_rooms.c \
		   throw_error.c \
		   debug.c
SRCDIR = ./srcs/
OBJDIR = ./objs/
INCDIR = ./includes/
LIBFTL = -L./libft -lft

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTL) -o $(NAME)

clean:
	make -C ./libft clean
	rm -fr $(OBJDIR)

fclean:
	make -C ./libft fclean
	rm -fr $(OBJDIR)
	rm -f $(NAME)

re: fclean all
