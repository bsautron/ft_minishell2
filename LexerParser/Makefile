# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/03 22:55:20 by ihermell          #+#    #+#              #
#    Updated: 2015/05/28 23:03:06 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME        = liblexpar.a

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Ofast

OBJ_DIRS = ../.obj/ \
           ../.obj/lexpar/ \
           ../.obj/lexpar/lexer/ \
           ../.obj/lexpar/lexer/helpers/ \
           ../.obj/lexpar/lexer/state/ \
           ../.obj/lexpar/lexer/state/list/ \
           ../.obj/lexpar/lexer/token/ \
           ../.obj/lexpar/token/ \
           ../.obj/lexpar/lexer/state_flows/ \
           ../.obj/lexpar/lexer/errors/ \
           ../.obj/lexpar/parser/ \
           ../.obj/lexpar/parser/tree/

EXT_SRC     =

SRC_DIR_LEX = lexer/
SRC_DIR_PAR = parser/

SRC_NAME_LEX = lexer.c \
               init_lexer.c \
			   free_lexer.c \
               next_token.c \
               char_to_category.c \
               \
               helpers/ignore_character.c \
               helpers/pop_clear_token.c \
               helpers/pop_state_pop_token.c \
               helpers/push_state_and_chain.c \
               helpers/ignore_push_state_and_chain.c \
               helpers/push_to_token_and_pop.c \
               helpers/ignore_and_pop_token.c \
               \
               state/pop_state.c \
               state/push_state.c \
               state/list/new_state_list.c \
               state/list/pop_state_list.c \
               state/list/push_state_list.c \
			   state/list/free_state_list.c \
               \
               token/pop_token.c \
               token/push_to_token.c \
               token/clear_token.c \
               ../token/new_token_list.c \
               ../token/push_token_list.c \
               ../token/push_back_token_list.c \
               ../token/token_to_priority.c \
               ../token/max_priority_token.c \
               ../token/head_token_list.c \
               ../token/free_token_list.c \
               \
               state_flows/default_state_flow.c \
               state_flows/cmd_arg_state_flow.c \
               state_flows/inhb_cmd_arg_state_flow.c \
               state_flows/backslash_state_flow.c \
               state_flows/and_operator_state_flow.c \
               state_flows/or_operator_state_flow.c \
               state_flows/subcommand_state_flow.c \
               \
               errors/e_syntax_error.c \
               errors/e_unclosed_quote.c \
               errors/e_unclosed_parenthesis.c


SRC_NAME_PAR = parser.c \
               tree/new_btree.c \
               tree/print_tree.c

SRC_LEX     = $(addprefix $(SRC_DIR_LEX),$(SRC_NAME_LEX))
SRC_PAR     = $(addprefix $(SRC_DIR_PAR), $(SRC_NAME_PAR))

SRC         = $(SRC_LEX)
SRC         += $(SRC_PAR)
SRC         += lex_and_parse.c

OBJ         = $(SRC:%.c=../.obj/lexpar/%.o)

LIBFT_DIR   = ../libft/
LIBFT_NAME  = libft.a
LIBFT       = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC_DIR     = -I . \
              -I $(addprefix ../, includes/) \
              -I $(addprefix lexer/, include/) \
              -I $(addprefix lexer/, ../token/include/) \
              -I $(addprefix parser/, include/)

LIBRARIES   = -L $(LIBFT_DIR) -lft


all: dor $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo "---- Wassup Lexer? ----"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "LEX."

dor:
	@mkdir $(OBJ_DIRS) 2> /dev/null || env -i

../.obj/lexpar/%.o: %.c
	@echo $<
	$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<;

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
