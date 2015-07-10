/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_state_flow.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 07:51:07 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/10 08:04:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token		*left_redirection_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	if (c == '>' && lexer->token_length < 2)
		return (push_to_token(c, lexer));
	if (lexer->token_length < 2)
		return (pop_state_pop_token(TK_LEFT_REDIRECTION, lexer));
	(void)cat;
	return (pop_state_pop_token(TK_DLEFT_REDIRECTION, lexer));
}
