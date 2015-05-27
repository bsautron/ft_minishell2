/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_unclosed_parenthesis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 01:01:38 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 01:03:17 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*e_unclosed_parenthesis(t_lexer *lexer)
{
	ft_putstr_fd("Unclosed parenthesis starting at column ", 2);
	ft_putnbr_fd(lexer->pos - lexer->token_length - 1, 2);
	ft_putstr_fd(", concerned token : (", 2);
	lexer->token[lexer->token_length] = '\0';
	ft_putstr_fd(lexer->token, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
	return (NULL);
}
