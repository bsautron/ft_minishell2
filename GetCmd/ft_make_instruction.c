/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 18:25:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 14:30:39 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_make_instruction(char *id, char *area)
{
	char	*res;

	if ((res = tgetstr(id, &area)) == NULL)
	{
		ft_reset_term();
		ft_putstr_fd(id, 2);
		ft_putendl_fd(": tgetstr Failed", 2);
		exit(1);
	}
	tputs(res, 0, ft_outc);
}
