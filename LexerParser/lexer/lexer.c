/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 00:02:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/22 21:40:34 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

t_token			*lex(char *str, int *status)
{
	t_lexer		*lexer;
	t_token		*tk_list;
	t_token		*token;

	tk_list = NULL;
	lexer = init_lexer(str);
	while ((token = next_token(str, lexer)) != NULL)
		push_back_token_list(token, &tk_list);
	*status = lexer->status;
	if (lexer->status == STATUS_ERROR)
	{
		free_token_list(tk_list);
		return (NULL);
	}
	free_lexer(lexer);
	return (tk_list);
}
