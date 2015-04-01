/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_alt_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 02:37:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/01 02:57:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	ft_uup(int *pos)
{
	if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
	{
		ft_make_instruction("up", NULL);
		ft_putstr("\033[");
		ft_putstr(ft_itoa(g_env.win_col));
		ft_putstr("C");
	}
	ft_make_instruction("le", NULL);
}

void	ft_key_alt_left(int *pos)
{
	if (*pos == 0 && ft_lstl_len(g_env.cmd))
	{
		ft_make_instruction("le", NULL);
		ft_uup(pos);
		(*pos)++;
	}
	while (*pos < ft_lstl_len(g_env.cmd) && ft_lstl_get_link_by_id(g_env.cmd, *pos - 1)->str[0] == ' ')
	{
		ft_uup(pos);
		(*pos)++;
	}
	while (*pos < ft_lstl_len(g_env.cmd) && ft_lstl_get_link_by_id(g_env.cmd, *pos - 1)->str[0] != ' ')
	{
		ft_uup(pos);
		(*pos)++;
	}
}
