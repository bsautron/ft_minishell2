/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 19:19:44 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/25 19:26:55 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_scope_pop(t_scope **begin)
{
	void	*tmp;

	if (begin && *begin)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}
}
