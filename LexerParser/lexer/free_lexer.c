/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:21:00 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/19 14:33:12 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void			free_lexer(t_lexer *lexer)
{
	free_state_list(lexer->state);
	free(lexer->state_flows);
	free(lexer);
}
