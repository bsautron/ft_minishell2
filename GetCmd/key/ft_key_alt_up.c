/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_alt_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 02:57:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/05 06:27:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_key_alt_up(int *pos)
{
	int		i;

	i = 0;
	if (ft_lstl_len(g_env.cmd) - *pos + 1 + (int)ft_strlen(g_env.prompt) > g_env.win_col - 1)
	{
		while (i < g_env.win_col - 1 && *pos < ft_lstl_len(g_env.cmd))
		{
			if ((ft_lstl_len(g_env.cmd) - *pos + (int)ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
			{
				ft_make_instruction("up", NULL);
				ft_putstr("\033[");
				ft_putstr(ft_itoa(g_env.win_col));
				ft_putstr("C");
			}
			(*pos)++;
			ft_make_instruction("le", NULL);
			i++;
		}
	}
}
