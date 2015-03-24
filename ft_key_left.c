/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 02:47:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/24 02:47:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_left(int *pos)
{
	if (*pos < ft_lstl_len(g_env.cmd))
	{
		(*pos)++;
		ft_make_instruction("le", NULL);
		ft_make_instruction("im", NULL);
	}
}
