/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:11:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 03:09:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_nbargv(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] > ' ' && (str[i + 1] <= ' ' || !str[i + 1]))
				nb++;
			i++;
		}
	}
	return (nb);
}
