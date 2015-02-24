/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 18:25:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 18:38:11 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <term.h>

void	ft_make_instruction(char *id, char *aera)
{
	char	*res;

	if ((res = tgetstr(id, &aera)) == NULL)
	{
		ft_tcg(1);
		ft_putendl_fd("ft_make_instruction(): tgetstr Failed", 2);
		exit(1);
	}
	tputs(res, 0, ft_outc);
}
