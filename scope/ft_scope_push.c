/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:03:59 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/24 15:24:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scope.h>
# include <stdio.h>

void	ft_scope_push(t_scope **begin, int id)
{
	t_scope	*new;

	new = ft_scope_create(id);
	if (!(*begin))
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}
