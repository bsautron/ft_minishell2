/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 07:37:44 by bsautron          #+#    #+#             */
/*   Updated: 2015/04/05 06:30:41 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void		ft_key_right(int *pos)
{
	if (*pos != 0)
	{
		(*pos)--;
		ft_make_instruction("nd", NULL);
		if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen(g_env.prompt)) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("do", NULL);
		}
	}
	if (*pos == 0)
		ft_make_instruction("ei", NULL);
}
