/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 02:47:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/24 07:16:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_left(int *pos)
{
	if (*pos < ft_lstl_len(g_env.cmd))
	{
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("up", NULL);
			g_env.nb_line--;
			ft_putstr("\033[");
			ft_putstr(ft_itoa(g_env.win_col));
			ft_putstr("C");
		}
		(*pos)++;
		ft_make_instruction("le", NULL);
		ft_make_instruction("im", NULL);
	}
}
