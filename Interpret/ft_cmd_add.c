/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 05:07:27 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/08 06:08:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interpret.h>

void    ft_cmd_add(t_cmd **begin, t_cmd *cmd)
{
	t_cmd  *new;

	new = cmd;
	if (!(*begin))
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}
