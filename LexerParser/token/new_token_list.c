/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 23:52:48 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 22:55:51 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <libft.h>

t_token				*new_token_list(char *value, t_tk_type type)
{
	t_token			*tk;

	tk = (t_token *)malloc(sizeof(t_token));
	tk->value = value;
	tk->type = type;
	tk->prev = NULL;
	tk->next = NULL;
	return (tk);
}
