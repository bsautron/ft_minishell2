/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 18:02:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/25 22:35:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_signal_handler(int sig)
{
	struct winsize	winsize;

	if (sig == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &winsize);
		g_env.win_col = winsize.ws_col;
		//ft_refresh();
	}
	if (sig == SIGINT)
	{
		ft_reset_term();
		ft_putendl("ctrl + c: on verra");
		exit(1);
	}
}
