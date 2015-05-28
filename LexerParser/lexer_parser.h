/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:57:35 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/19 13:59:38 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

#include <lexer.h>
#include <parser.h>
#include <token.h>

t_btree			*lex_and_parse(char *str, int *status);

#endif
