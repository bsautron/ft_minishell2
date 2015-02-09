/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:53:26 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/07 04:47:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		g_stop;

void	ft_stop(int sig)
{
	g_stop = 0;
	if (sig == 1)
		g_stop = 1;
	/*
	ft_putchar('\n');
	ft_putstr("\x1b[31m");
	ft_putchar(-30);
	ft_putchar(-98);
	ft_putchar(-100);
	ft_putchar(' ');
	ft_putstr("\033[1;31;47m");
	ft_putstr(ft_get_dirname());
	ft_putstr("\033[0;37;40m ");*/
}
