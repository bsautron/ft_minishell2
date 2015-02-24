# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 12:21:35 by bsautron          #+#    #+#              #
#    Updated: 2015/02/24 20:11:40 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = ft_lstl_create.c \
	  ft_lstl_add.c \
	  ft_lstl_add_back.c \
	  ft_lstl_insert.c \
	  ft_lstl_delone.c \
	  ft_lstl_delone_by_id.c \
	  ft_lstl_len.c \
	  ft_lstl_print.c
OBJ = $(SRC:.c=.o)
NAME = libl.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[37m"

%.o: %.c
	@echo "\033[31m   $^"
	@$(CC) $(CFLAGS) -I ../includes/ -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
