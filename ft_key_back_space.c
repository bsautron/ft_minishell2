/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_back_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 00:34:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/24 02:32:35 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_back_space(int *pos)
{
	if (*pos < ft_lstl_len(g_env.cmd))
	{
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
	}
	if ((ft_lstl_len(g_env.cmd) + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == g_env.win_col - 2)
	{
		ft_make_instruction("up", NULL);
		g_env.nb_line--;
		ft_putstr("\033[");
		ft_putstr(ft_itoa(g_env.win_col));
		ft_putstr("C");
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
	}
}
