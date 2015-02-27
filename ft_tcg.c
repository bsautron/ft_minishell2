/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:02:41 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 14:20:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_tcg(t_env *env)
{
	char			*name_term;
	struct termios	term;

	env = env;
	if ((name_term = getenv("TERM")) == NULL)
		exit(1);
	//name_term = ft_get_env("TERM");
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
