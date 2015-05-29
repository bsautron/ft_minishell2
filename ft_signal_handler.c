/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 18:02:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/29 12:27:48 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl("ctrl + c: on verra");
		exit(1);
	}
}
