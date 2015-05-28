/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_state_flow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 01:17:25 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 23:58:52 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*default_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	if (cat == CHAR_WHITESPACE)
		return (ignore_character(lexer));
	else if (cat == CHAR_END)
		return (NULL);
	else if (cat == CHAR_ALPHA || cat == CHAR_NUM || c == '-' || c == '\\'
		|| c == '/' || c == '.' || c == '_')
		return (push_state_and_chain(STATE_CMD_ARG, lexer));
	else if (c == ';')
		return (push_to_token_and_pop(c, TK_CMD_SEPARATOR, lexer));
	else if (c == '&')
		return (push_state_and_chain(STATE_AND_OPERATOR, lexer));
	else if (c == '|')
		return (push_state_and_chain(STATE_OR_OPERATOR, lexer));
	else if (c == '"')
		return (ignore_push_state_and_chain(STATE_INHB_CMD_ARG, lexer));
	else if (c == '(')
		return (ignore_push_state_and_chain(STATE_SUBCOMMAND, lexer));
	(void)c;
	return (e_syntax_error(lexer));
}
