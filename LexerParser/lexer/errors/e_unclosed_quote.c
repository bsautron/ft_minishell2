/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_unclosed_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 00:36:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 00:57:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*e_unclosed_quote(t_lexer *lexer)
{
	ft_putstr_fd("Unclosed quote starting at column ", 2);
	ft_putnbr_fd(lexer->pos - lexer->token_length - 1, 2);
	ft_putstr_fd(", concerned token : \"", 2);
	lexer->token[lexer->token_length] = '\0';
	ft_putstr_fd(lexer->token, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
	return (NULL);
}
