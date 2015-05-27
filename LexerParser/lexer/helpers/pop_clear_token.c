/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_clear_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 01:29:21 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 00:24:13 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*pop_clear_token(t_tk_type type, t_lexer *lexer)
{
	t_token		*token;

	token = pop_token(type, lexer);
	clear_token(lexer);
	return (token);
}
