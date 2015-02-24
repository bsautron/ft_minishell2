/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstl_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:22:49 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 19:50:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libl.h"

void	ft_lstl_print(t_lstl *list)
{
	while (list)
	{
		ft_putstr(list->str);
		list = list->next;
		if (list)
			ft_putchar('\n');
	}
}
