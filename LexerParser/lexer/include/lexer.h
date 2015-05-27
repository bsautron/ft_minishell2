/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 00:02:22 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 13:14:56 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

// LOL
#include <stdio.h>
# include <stdlib.h>

# include "libft.h"
# include "token.h"

# define NB_STATE_FLOWS 7

struct					s_lexer;
typedef struct			s_lexer t_lexer;

typedef enum			e_estate
{
	STATE_DEFAULT,
	STATE_INHB_CMD_ARG,
	STATE_CMD_ARG,
	STATE_AND_OPERATOR,
	STATE_OR_OPERATOR,
	STATE_SUBCOMMAND,
	STATE_BACKSLASH
}						t_estate;

typedef enum			e_char_cat
{
	CHAR_END,
	CHAR_DEFAULT,
	CHAR_WHITESPACE,
	CHAR_ALPHA,
	CHAR_NUM
}						t_char_cat;

typedef struct			s_state
{
	int					id;
	struct s_state		*prev;
	struct s_state		*next;
}						t_state;

typedef t_token*		(*t_state_flow)(char, t_char_cat, t_lexer *);

struct					s_lexer
{
	char				*str;
	int					pos;
	char				token[1024];
	int					token_length;
	int					depth;
	t_state				*state;
	t_state_flow		*state_flows;
};

t_token					*lex(char *str);

t_lexer					*init_lexer();
t_token					*next_token(char *str, t_lexer *lexer);

int						char_to_category(char c);

t_token					*ignore_character(t_lexer *lexer);
t_token					*pop_clear_token(t_tk_type type, t_lexer *lexer);
t_token					*pop_state_pop_token(t_tk_type type, t_lexer *lexer);
t_token					*ignore_push_state_and_chain(t_estate state, t_lexer *lexer);
t_token					*push_state_and_chain(t_estate state, t_lexer *lexer);
t_token					*push_to_token_and_pop(char c, t_tk_type type,
						t_lexer *lexer);
t_token					*ignore_and_pop_token(t_tk_type type, t_lexer *lexer);

void					pop_state(t_lexer *lexer);
void					push_state(t_estate state, t_lexer *lexer);

t_token					*pop_token(t_tk_type type, t_lexer *lexer);
void					clear_token(t_lexer *lexer);
t_token					*push_to_token(char c, t_lexer *lexer);

t_token					*default_state_flow(char c, t_char_cat cat, t_lexer *lexer);
t_token					*cmd_arg_state_flow(char c, t_char_cat cat, t_lexer *lexer);
t_token					*inhb_cmd_arg_state_flow(char c, t_char_cat cat, t_lexer *lexer);
t_token					*backslash_state_flow(char c, t_char_cat cat, t_lexer *lexer);
t_token					*and_operator_state_flow(char c, t_char_cat cat, t_lexer *lexer);
t_token					*or_operator_state_flow(char c, t_char_cat cat, t_lexer *lexer);
t_token					*subcommand_state_flow(char c, t_char_cat cat, t_lexer *lexer);

t_token					*e_syntax_error(t_lexer *lexer);
t_token					*e_unclosed_quote(t_lexer *lexer);
t_token					*e_unclosed_parenthesis(t_lexer *lexer);

t_state					*new_state_list(t_estate state);
void					pop_state_list(t_state **state_list);
void					push_state_list(t_state *state, t_state **state_list);

#endif
