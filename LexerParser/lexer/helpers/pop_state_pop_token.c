/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_state_pop_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:23:26 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:53:56 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*pop_state_pop_token(t_tk_type type, t_lexer *lexer)
{
	pop_state(lexer);
	return (pop_clear_token(type, lexer));
}
