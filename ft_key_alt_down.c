/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_alt_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 03:38:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/03 05:31:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_key_alt_down(int *pos)
{
	int		i;

	i = 0;
	if (((ft_lstl_len(g_env.cmd) + ft_strlen("DtaPrompt> ")) % (g_env.win_col - 1) < (ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) && *pos < g_env.win_col) || *pos > g_env.win_col - 2)
	{
		while (i < g_env.win_col - 1 && *pos)
		{
			(*pos)--;
			ft_make_instruction("nd", NULL);
			if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen("Datpromt> ")) % (g_env.win_col - 1) == 0)
				ft_make_instruction("do", NULL);
			i++;
		}
		ft_make_instruction("nd", NULL);
	}
}
