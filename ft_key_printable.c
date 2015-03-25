/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_printable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 00:39:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/25 15:18:30 by bsautron         ###   ########.fr       */
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

void		ft_key_printable(char *buf, int *pos)
{
	int		no_pos;

	g_env.h_pos = 0;
	ft_lstl_insert(&g_env.cmd, buf, *pos);
	if (*pos == 0)
	{
		ft_putchar(buf[0]);
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("do", NULL);
		}
	}
	else
	{
		no_pos = *pos;
		ft_key_home(&no_pos);
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("do", NULL);
			ft_putstr("\033[");
			ft_putstr(ft_itoa(ft_strlen("DatPrompt> ")));
			ft_putstr("C");
		}
		if (ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ") < g_env.win_col - 1)
			ft_make_instruction("nd", NULL);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_lstl_to_str(g_env.cmd));
		ft_move_cursor(*pos);
	}
}
