# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 12:21:35 by bsautron          #+#    #+#              #
#    Updated: 2015/06/30 17:37:15 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
OBJ_DIRS = ../.obj/ \
		   ../.obj/libld/
SRC = ft_lstld_create.c \
	  ft_lstld_add.c \
	  ft_lstld_free.c \
	  ft_lstld_len.c \
	  ft_lstld_print.c

OBJ = $(SRC:%.c=../.obj/libld/%.o)
	NAME = libld.a
	CFLAGS = -Wall -Wextra -Werror

all: dor $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0m"

dor:
	@mkdir $(OBJ_DIRS) 2> /dev/null || env -i

../.obj/libld/%.o: %.c includes/libld.h ../libft/includes/libft.h
	@echo "\033[31m   $<"
	@$(CC) -o $@ $(CFLAGS) -I includes/ -I ../libft/includes/ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIRS) 2> /dev/null || echo '' > /dev/null

fclean: clean
	@rm -f $(NAME)

re: fclean all
