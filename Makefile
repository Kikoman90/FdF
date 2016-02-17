# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsidler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 13:47:47 by fsidler           #+#    #+#              #
#    Updated: 2016/02/17 17:15:53 by fsidler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
LIB_NAME = ft
LIBDIR = libft
FLAGS = -Wall -Wextra -Werror -O3

SOURCES = main.c \
		  error.c \
		  draw.c \

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIBDIR)/lib$(LIB_NAME).a $(OBJECTS)
	$(CC) -L $(LIBDIR) -l $(LIB_NAME) -o $@ $^ -lmlx -framework OpenGL -framework AppKit
	@echo "compiling [ $(NAME) ] SUCCESS"

$(LIBDIR)/lib$(LIB_NAME).a : 
	$(MAKE) -C $(LIBDIR)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBDIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
