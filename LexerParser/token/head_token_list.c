/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:26:24 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 12:50:02 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <token.h>

t_token			*head_token_list(t_token *tk_list)
{
	while (tk_list && tk_list->prev)
		tk_list = tk_list->prev;
	return (tk_list);
}
