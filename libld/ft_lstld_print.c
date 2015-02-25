/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:22:49 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:29:20 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libld.h"

void	ft_lstld_print(t_lstld *list)
{
	while (list)
	{
		ft_putstr(list->str);
		list = list->next;
		if (list)
			ft_putchar('\n');
	}
}
