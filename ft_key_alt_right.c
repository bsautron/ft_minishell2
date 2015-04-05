/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_alt_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 01:57:51 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/05 06:36:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	ft_doo(int *pos)
{
	if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
		ft_make_instruction("do", NULL);
}

void	ft_key_alt_right(int *pos)
{
	if (*pos)
	{
		while (*pos - 1 && ft_lstl_get_link_by_id(g_env.cmd, *pos - 1)->str[0] == ' ')
		{
			(*pos)--;
			ft_make_instruction("nd", NULL);
			ft_doo(pos);
		}
		while (*pos - 1 && ft_lstl_get_link_by_id(g_env.cmd, *pos - 1)->str[0] != ' ')
		{
			(*pos)--;
			ft_make_instruction("nd", NULL);
			ft_doo(pos);
		}
	}
	if (*pos == 1)
	{
		(*pos)--;
		ft_make_instruction("nd", NULL);
		ft_doo(pos);
	}
}
