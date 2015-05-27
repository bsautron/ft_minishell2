/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inhb_cmd_arg_state_flow.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:31:24 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 02:06:16 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*inhb_cmd_arg_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	if (c == '"')
	{
		pop_state(lexer);
		return (ignore_and_pop_token(TK_CMD_ARG, lexer));
	}
	if (c == '\0')
		return (e_unclosed_quote(lexer));
	(void)cat;
	return (push_to_token(c, lexer));
}
