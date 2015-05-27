/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 01:10:38 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:44:41 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*pop_token(t_tk_type type, t_lexer *lexer)
{
	t_token		*new_tk;

	lexer->token[lexer->token_length] = '\0';
	new_tk = new_token_list(ft_strdup(lexer->token), type);
	return (new_tk);
}
