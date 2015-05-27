/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_category.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 01:14:59 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/12 00:15:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int				char_to_category(char c)
{
	if (c == ' ' || c == '\t')
		return (CHAR_WHITESPACE);
	if (ft_isalpha(c))
		return (CHAR_ALPHA);
	if (ft_isdigit(c))
		return (CHAR_NUM);
	if (c == '\0')
		return (CHAR_END);
	return (CHAR_DEFAULT);
}
