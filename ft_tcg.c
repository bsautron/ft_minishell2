/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 05:58:23 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 05:58:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_tcg(char f)
{
	static int				fd;
	static struct termios	term_attributes;

	fd = STDOUT_FILENO;
	if (f == 0)
	{
		tcgetattr(fd, &term_attributes);
		term_attributes.c_lflag &= ~(ICANON);
		term_attributes.c_lflag = term_attributes.c_lflag
			& ~(ECHOK | ECHO | ECHONL | ECHOE | IEXTEN);
		term_attributes.c_lflag &= ~(ECHO);
		term_attributes.c_cc[VMIN] = 1;
		term_attributes.c_cc[VTIME] = 0;
		tcsetattr(fd, TCSADRAIN, &term_attributes);
	}
	else
	{
		term_attributes.c_lflag = term_attributes.c_lflag | ICANON;
		term_attributes.c_lflag = term_attributes.c_lflag | ECHO;
		tcsetattr(fd, TCSADRAIN, &term_attributes);
	}
}
