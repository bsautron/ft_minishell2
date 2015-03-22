# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 12:21:35 by bsautron          #+#    #+#              #
#    Updated: 2015/02/25 20:30:05 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = ft_lstld_create.c \
	  ft_lstld_add.c \
	  ft_lstld_free.c \
	  ft_lstld_len.c \
	  ft_lstld_print.c
OBJ = $(SRC:%.c=../.obj/%.o)
NAME = libld.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0m"

../.obj/%.o: %.c ../includes/libld.h ../includes/libft.h
	@echo "\033[31m   $<"
	@$(CC) -o $@ $(CFLAGS) -I ../includes/ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
