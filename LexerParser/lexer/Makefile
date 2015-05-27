# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/03 22:55:20 by ihermell          #+#    #+#              #
#    Updated: 2015/05/16 13:11:12 by ihermell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME		= a.out

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Ofast

EXT_SRC		= 

SRC_DIR		=
SRC_NAME	= main.c \
			  lexer.c \
			  init_lexer.c \
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
			  \
			  token/pop_token.c \
			  token/push_to_token.c \
			  token/clear_token.c \
			  ../token/push_token_list.c \
			  ../token/push_back_token_list.c \
			  ../token/new_token_list.c \
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

SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= obj/
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ			= $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIBFT_DIR	= Libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC_DIR		= -I $(addprefix $(LIBFT_DIR), include/) \
			  -I include/ \
			  -I ../token/include

LIBRARIES	= -L $(LIBFT_DIR) -lft

all : $(NAME)

$(NAME): $(LIBFT) $(SRC) $(EXT_SRC)
	@echo ""
	@echo "---- Wassup Lexer? ----"
	@$(CC) $(CFLAGS) $(INC_DIR) $(LIBRARIES) $(EXT_SRC) $(SRC) -o $(NAME)
	@echo "LEX."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<;
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

$(LIBFT):
	@make -C $(LIBFT_DIR) re

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@make -C $(LIBFT_DIR) clean
	@echo "-- So clean."

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
