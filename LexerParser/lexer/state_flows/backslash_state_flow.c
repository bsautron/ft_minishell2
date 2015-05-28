/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_state_flow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 02:07:42 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 21:45:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*backslash_state_flow(char c, t_char_cat cat, t_lexer *lexer)
{
	push_to_token(c, lexer);
	pop_state(lexer);
	(void)cat;
	return (NULL);
}
