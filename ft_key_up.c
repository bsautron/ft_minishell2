/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 02:58:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/01 02:12:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_key_up(int *pos)
{
	if (g_env.h_pos == 0)
		g_env.cmd_saved = g_env.cmd;
	if (g_env.h_pos < ft_lstld_len(g_env.history))
	{
		ft_key_home(pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_lstld_get_link_by_id(g_env.history, g_env.h_pos)->str);
		g_env.cmd = ft_str_to_lstl(
				ft_lstld_get_link_by_id(g_env.history, g_env.h_pos)->str);
		*pos = 0;
		g_env.h_pos++;
	}
}
