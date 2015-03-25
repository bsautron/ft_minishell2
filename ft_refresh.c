/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 21:21:41 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/25 21:38:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_refresh(void)
{
	int		no_pos;

	if (g_env.cmd)
	{
		no_pos = g_env.pos;
		ft_key_home(&no_pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_lstl_to_str(g_env.cmd));
		ft_move_cursor(g_env.pos);
	}
}
