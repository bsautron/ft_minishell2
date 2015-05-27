/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlyesp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 05:18:35 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/26 02:49:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_onlyesp(char *str)
{
	int		i;
	int		ret;

	ret = 1;
	i = 0;
	while (str && str[i])
	{
		if (str[i] > ' ')
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
