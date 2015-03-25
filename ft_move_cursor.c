/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 21:25:08 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/25 21:25:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_move_cursor(int pos)
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
