/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_token_and_pop.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:24:30 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 00:26:37 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*push_to_token_and_pop(char c, t_tk_type type, t_lexer *lexer)
{
	push_to_token(c, lexer);
	return (pop_clear_token(type, lexer));
}
