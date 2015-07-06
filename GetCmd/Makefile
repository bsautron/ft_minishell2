# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/03 22:55:20 by ihermell          #+#    #+#              #
#    Updated: 2015/06/09 22:49:14 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME		= libgetcmd.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Ofast

OBJ_DIRS = ../.obj/ \
		   ../.obj/getcmd/ \
		   ../.obj/getcmd/key/ \
		   ../.obj/getcmd/scope/

EXT_SRC		= 

SRC_DIR_KEY = key/
SRC_DIR_SCOPE = scope/

SRC_NAME_MAIN = ft_get_cmd.c \
				ft_get_dirname.c \
				ft_get_home.c \
				ft_lstl_get_link_by_id.c \
				ft_lstl_to_str.c \
				ft_lstld_get_link_by_id.c \
				ft_make_instruction.c \
				ft_move_cursor.c \
				ft_onlyesp.c \
				ft_outc.c \
				ft_print_list_char.c \
				ft_putstr_spec.c \
				ft_refresh.c \
				ft_replace.c \
				ft_reset_term.c \
				ft_set_term.c \
				ft_str_to_lstl.c

SRC_NAME_KEY = ft_key_alt_down.c \
			   ft_key_alt_left.c \
			   ft_key_alt_right.c \
			   ft_key_alt_up.c \
			   ft_key_back_space.c \
			   ft_key_ctrl_d.c \
			   ft_key_ctrl_v.c \
			   ft_key_delete.c \
			   ft_key_down.c \
			   ft_key_end.c \
			   ft_key_home.c \
			   ft_key_left.c \
			   ft_key_printable.c \
			   ft_key_right.c \
			   ft_key_up.c

SRC_NAME_SCOPE = ft_scope_bquote.c \
				 ft_scope_cursh.c \
				 ft_scope_default.c \
				 ft_scope_dquote.c \
				 ft_scope_free.c \
				 ft_scope_hook.c \
				 ft_scope_len.c \
				 ft_scope_new.c \
				 ft_scope_pop.c \
				 ft_scope_print.c \
				 ft_scope_push.c \
				 ft_scope_quote.c \
				 ft_scope_subsh.c

SRC_MAIN	= $(SRC_NAME_MAIN)
SRC_KEY		= $(addprefix $(SRC_DIR_KEY), $(SRC_NAME_KEY))
SRC_SCOPE	= $(addprefix $(SRC_DIR_SCOPE), $(SRC_NAME_SCOPE))

SRC			= $(SRC_MAIN)
SRC			+= $(SRC_KEY)
SRC			+= $(SRC_SCOPE)

OBJ			= $(SRC:%.c=../.obj/getcmd/%.o)

LIBFT_DIR	= ../libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC_DIR		= -I . \
			  -I includes/ \
			  -I ../libft/includes/ \
			  -I ../libl/includes/ \
			  -I ../libld/includes/

LIBRARIES	= -L $(LIBFT_DIR) -lft


all: dor $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo "---- Wassup Cmd? ----"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Let's CMD."

dor:
	@mkdir $(OBJ_DIRS) 2> /dev/null || env -i

../.obj/getcmd/%.o: %.c
	@echo $<
	@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<;

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ)
	@rmdir $(OBJ_DIRS) 2> /dev/null || echo '' > /dev/null
	@make -C $(LIBFT_DIR) clean
	@echo "-- So clean."

fclean: clean
	@rm -rf $(NAME)

re: fclean all
