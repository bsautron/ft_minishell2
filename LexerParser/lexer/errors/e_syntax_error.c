/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_syntax_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 01:46:27 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/19 14:04:06 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*e_syntax_error(t_lexer *lexer)
{
	lexer->status = STATUS_ERROR;
	ft_putstr_fd("Syntax error near '", 2);
	ft_putchar_fd(lexer->str[lexer->pos], 2);
	ft_putstr_fd("', at column ", 2);
	ft_putnbr_fd(lexer->pos, 2);
	ft_putstr_fd(", unexpected character", 2);
	ft_putstr_fd(" (state ", 2);
	ft_putnbr_fd(lexer->state->id, 2);
	ft_putstr_fd(")\n", 2);
	return (NULL);
}
