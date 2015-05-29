/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attrape_moi_si_tu_peux.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 11:39:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/29 11:41:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	ft_attrape_moi_si_tu_peux(void)
{
	signal(SIGINT, ft_signal_handler);
	signal(SIGWINCH, ft_signal_handler);
}
