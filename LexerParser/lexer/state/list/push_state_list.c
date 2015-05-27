/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_state_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 05:42:21 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:42:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void			push_state_list(t_state *state, t_state **state_list)
{
	state->next = *state_list;
	state->prev = NULL;
	if (*state_list)
		(*state_list)->prev = state;
	*state_list = state;
}
