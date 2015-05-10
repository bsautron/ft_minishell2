/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_printable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 00:39:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/05 06:30:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_printable(char *buf, int *pos)
{
	int		no_pos;
	char	*tmp;

	g_env.h_pos = 0;
	ft_lstl_insert(&g_env.cmd, buf, *pos);
	ft_lstl_insert(&g_env.cmd_returned, buf, *pos);
	if (*pos == 0)
	{
		ft_putchar(buf[0]);
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
			ft_make_instruction("do", NULL);
	}
	else
	{
		no_pos = *pos;
		ft_key_home(&no_pos);
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("do", NULL);
			ft_putstr("\033[");
			ft_putstr(ft_itoa(ft_strlen(g_env.prompt)));
			ft_putstr("C");
		}
		if (ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt) < g_env.win_col - 1)
			ft_make_instruction("nd", NULL);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		tmp = ft_lstl_to_str(g_env.cmd);
		ft_putstr_spec(tmp);
		free(tmp);
		ft_move_cursor(*pos);
	}
}
