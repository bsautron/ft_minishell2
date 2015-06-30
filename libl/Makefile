# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 12:21:35 by bsautron          #+#    #+#              #
#    Updated: 2015/06/09 22:52:13 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libl.a
CFLAGS = -Wall -Wextra -Werror

OBJ_DIRS = ../.obj/ \
		   ../.obj/libl/

SRC = ft_lstl_create.c \
	  ft_lstl_add.c \
	  ft_lstl_add_back.c \
	  ft_lstl_insert.c \
	  ft_lstl_clone.c \
	  ft_lstl_free.c \
	  ft_lstl_delone.c \
	  ft_lstl_delone_by_id.c \
	  ft_lstl_len.c \
	  ft_lstl_print.c

OBJ = $(SRC:%.c=../.obj/libl/%.o)

all: dor $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[37m"

dor:
	@mkdir $(OBJ_DIRS) 2> /dev/null || env -i

../.obj/libl/%.o: %.c includes/libl.h ../libft/includes/libft.h
	@echo "\033[31m   $<"
	@$(CC) -o $@ $(CFLAGS) -I includes/ -I ../libft/includes/ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIRS) 2> /dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all
