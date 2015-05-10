/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_back_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 00:34:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/05 06:28:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_back_space(int *pos)
{
	int		no_pos;
	char	*tmp;

	g_env.h_pos = 0;
	if (*pos == 0 && ft_lstl_len(g_env.cmd))
	{
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("up", NULL);
			ft_putstr("\033[");
			ft_putstr(ft_itoa(g_env.win_col));
			ft_putstr("C");
		}
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
		ft_lstl_delone_by_id(&g_env.cmd_returned, *pos);
	}
	else if (ft_lstl_len(g_env.cmd) - *pos > 0)
	{
		no_pos = *pos;
		ft_key_home(&no_pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
		ft_lstl_delone_by_id(&g_env.cmd_returned, *pos);
		tmp = ft_lstl_to_str(g_env.cmd);
		ft_putstr_spec(tmp);
		free(tmp);
		ft_move_cursor(*pos);
	}
}
