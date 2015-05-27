/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arg_state_flow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:29:35 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 02:23:15 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*cmd_arg_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	if (c == '\\')
		return (ignore_push_state_and_chain(STATE_BACKSLASH, lexer));
	if (cat == CHAR_ALPHA || cat == CHAR_NUM || c =='-')
		return (push_to_token(c, lexer));
	return (pop_state_pop_token(TK_CMD_ARG, lexer));
}
