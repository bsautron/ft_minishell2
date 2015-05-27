/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_operator_state_flow.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 13:09:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 13:15:19 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*or_operator_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	if (c == '|' && lexer->token_length < 2)
		return (push_to_token(c, lexer));
	if (lexer->token_length < 2)
		return (e_syntax_error(lexer));
	(void)cat;
	return (pop_state_pop_token(TK_OR_OPERATOR, lexer));
}
