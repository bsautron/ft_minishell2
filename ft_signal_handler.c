/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 18:02:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 18:16:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_tcg(1);
		ft_putendl("ctrl + c: on verra");
		exit(1);
	}
}
