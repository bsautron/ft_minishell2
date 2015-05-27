/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 06:03:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:45:25 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void			push_state(t_estate state, t_lexer *lexer)
{
	push_state_list(new_state_list(state), &lexer->state);
}
