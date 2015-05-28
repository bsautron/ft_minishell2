/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 00:23:28 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 23:58:54 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*next_token(char *str, t_lexer *lexer)
{
	char		c;
	t_token		*token;


	token = NULL;
	while (42)
	{
		c = str[lexer->pos];
		token = (*lexer->state_flows[lexer->state->id])(c, char_to_category(c),
			lexer);
		if (token)
			return (token);
		else if (c == '\0' || lexer->status == STATUS_ERROR)
			return (NULL);
	}
	return (NULL);
}
