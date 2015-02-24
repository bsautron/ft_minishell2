/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:02:41 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 23:58:26 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <term.h>

void	ft_tcg(char f)
{
	char			*name_term;
	struct termios	term;

	if (f == 0)
	{
	if ((name_term = getenv("TERM")) == NULL)
		exit(1);
	if (tgetent(NULL, name_term) == -1)
		exit(1);
	if (tcgetattr(0, &term) == -1)
		exit(1);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term))
		exit(1);
	}
	else
	{
		ft_make_instruction("ei", NULL);
		tcgetattr(0, &term);
		term.c_lflag |= ICANON;
		term.c_lflag |= ECHO;
		tcsetattr(0, TCSADRAIN, &term);
	}
}
