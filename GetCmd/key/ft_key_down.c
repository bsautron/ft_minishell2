/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 15:32:10 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/01 02:12:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static t_lstl	*ft_str_to_lstl_spec(char *str)
{
	char	b[2];
	int		i;
	int		len;

	b[1] = 0;
	i = 0;
	len = ft_lstl_len(g_env.cmd);
	while (i < len)
	{
		ft_lstl_delone_by_id(&g_env.cmd_returned, 0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		b[0] = str[i];
		ft_lstl_add(&g_env.cmd_returned, b);
		i++;
	}
	return (g_env.cmd_returned);
}

void		ft_key_down(int *pos)
{
	char	*tmp;

	g_env.h_pos--;
	if (g_env.h_pos > 0)
	{
		ft_key_home(pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_lstld_get_link_by_id(g_env.history, g_env.h_pos - 1)->str);
		g_env.cmd_returned = ft_str_to_lstl_spec(
				ft_lstld_get_link_by_id(g_env.history, g_env.h_pos - 1)->str);
		g_env.cmd = ft_str_to_lstl(
				ft_lstld_get_link_by_id(g_env.history, g_env.h_pos - 1)->str);
		*pos = 0;
	}
	else if (g_env.h_pos == 0)
	{
		ft_key_home(pos);
		g_env.cmd = g_env.cmd_saved;
		g_env.cmd_returned = g_env.cmd_saved;
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		tmp = ft_lstl_to_str(g_env.cmd);
		ft_putstr_spec(tmp);
		free(tmp);
		*pos = 0;
	}
	else
		g_env.h_pos = 0;
}
