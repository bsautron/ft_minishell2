/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:15:31 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/11 23:43:30 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_state			*new_state_list(t_estate state)
{
	t_state		*ns;

	ns = (t_state*)malloc(sizeof(t_state));
	ns->id = state;
	ns->prev = NULL;
	ns->next = NULL;
	return (ns);
}
