/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_and_pop_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:35:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 00:52:26 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*ignore_and_pop_token(t_tk_type type, t_lexer *lexer)
{
	ignore_character(lexer);
	return (pop_clear_token(type, lexer));
}
