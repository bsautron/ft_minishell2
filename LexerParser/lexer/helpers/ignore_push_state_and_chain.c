/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_push_state_and_chain.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 02:04:02 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 02:04:10 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*ignore_push_state_and_chain(t_estate state, t_lexer *lexer)
{
	char		c;

	ignore_character(lexer);
	c = lexer->str[lexer->pos];
	push_state(state, lexer);
	return ((*lexer->state_flows[lexer->state->id])(c, char_to_category(c),
		lexer));
}
