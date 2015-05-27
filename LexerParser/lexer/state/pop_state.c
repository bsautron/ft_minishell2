/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:17:05 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:18:35 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void			pop_state(t_lexer *lexer)
{
	t_state		*tmp;

	if (lexer->state == NULL)
		return ;
	tmp = lexer->state;
	lexer->state = lexer->state->next;
	free(tmp);
}
