/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_back_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 00:34:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/24 07:37:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_move_cursor(int pos)
{
	int		i;

	i = 0;
	while (i < pos)
	{
		ft_make_instruction("le", NULL);
		if ((ft_lstl_len(g_env.cmd) - i + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("up", NULL);
			ft_putstr("\033[");
			ft_putstr(ft_itoa(g_env.win_col));
			ft_putstr("C");
			ft_make_instruction("le", NULL);
		}
		i++;
	}
}

void		ft_key_back_space(int *pos)
{
	int		no_pos;

	if ((ft_lstl_len(g_env.cmd) + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == g_env.win_col - 2)
		g_env.nb_line--;
	if (*pos == 0)
	{
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
	}
	else if (ft_lstl_len(g_env.cmd) - *pos > 0)
	{
		no_pos = *pos;
		ft_key_home(&no_pos);
		g_env.nb_line = 0;
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
		ft_putstr_spec(ft_lstl_to_str(g_env.cmd));
		ft_move_cursor(*pos);
	}
}
