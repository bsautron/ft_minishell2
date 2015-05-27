/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subcommand_state_flow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:57:59 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 02:04:56 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*subcommand_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	if (c == ')' && lexer->depth == 0)
	{
		pop_state(lexer);
		return (ignore_and_pop_token(TK_SUBCOMMAND, lexer));
	}
	if (c == '\0')
		return (e_unclosed_parenthesis(lexer));
	if (c == '(')
		lexer->depth++;
	else if (c == ')')
		lexer->depth--;
	(void)cat;
	return (push_to_token(c, lexer));
}
