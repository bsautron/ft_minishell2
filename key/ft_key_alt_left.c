/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_alt_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 02:37:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/05 06:27:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	ft_uup(int *pos)
{
	if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
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
	while (*pos < ft_lstl_len(g_env.cmd) && ft_lstl_get_link_by_id(g_env.cmd, *pos)->str[0] == ' ')
	{
		ft_uup(pos);
		(*pos)++;
	}
	while (*pos < ft_lstl_len(g_env.cmd) && ft_lstl_get_link_by_id(g_env.cmd, *pos)->str[0] != ' ')
	{
		ft_uup(pos);
		(*pos)++;
	}
}
