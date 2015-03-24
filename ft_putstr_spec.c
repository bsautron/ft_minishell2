/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 02:26:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/24 03:51:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_putstr_spec(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		ft_putchar(str[i]);
		if ((i + 1 + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("do", NULL);
			g_env.nb_line++;
		}
//		usleep(100000);
		i++;
	}
}
