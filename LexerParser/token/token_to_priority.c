/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_priority.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:10:01 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/19 14:42:08 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <token.h>

int			token_to_priority(t_token *token)
{
	if (token->type == TK_CMD_SEPARATOR)
		return (3);
	else if (token->type == TK_AND_OPERATOR
		|| token->type == TK_OR_OPERATOR)
		return (2);
	return (0);
}
