/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:22:49 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/23 18:38:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scope.h>

void	ft_scope_print(t_scope *list)
{
	while (list)
	{
		ft_putnbr(list->id);
		list = list->next;
		if (list)
			ft_putchar(' ');
	}
}
