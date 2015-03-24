/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 00:33:37 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/24 01:05:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_home(int *pos)
{
	int		i;

	while (*pos < ft_lstl_len(g_env.cmd))
	{
		if ((ft_lstl_len(g_env.cmd) + ft_strlen("DatPrompt> ") - *pos) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("up", NULL);
			ft_putstr("\033[");
			ft_putstr(ft_itoa(g_env.win_col));
			ft_putstr("C");
		}
		ft_make_instruction("le", NULL);
		(*pos)++;
	}
	*pos = ft_lstl_len(g_env.cmd);
	ft_make_instruction("im", NULL);
}
