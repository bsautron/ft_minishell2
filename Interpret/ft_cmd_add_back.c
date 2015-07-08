/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 05:09:34 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/08 06:07:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interpret.h>

void	ft_cmd_add_back(t_cmd **begin, t_cmd *cmd)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = cmd;
	if (!(*begin))
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
}
