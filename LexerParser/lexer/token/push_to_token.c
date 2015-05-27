/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 01:33:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:06:33 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*push_to_token(char c, t_lexer *lexer)
{
	lexer->token[lexer->token_length++] = c;
	lexer->pos++;
	return (NULL);
}
