/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 02:18:27 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 03:12:18 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_strtrim_new(char const *s)
{
	int		i;
	char	*tmp;
	char	*dst;

	tmp = (char *)s;
	dst = NULL;
	i = 0;
	if (tmp)
	{
		i = ft_strlen(s) - 1;
		while (i >= 0 && tmp[i] <= ' ')
		{
			tmp[i] = '\0';
			i--;
		}
		i = 0;
		while (tmp[i] && tmp[i] <= ' ')
			i++;
		dst = ft_strdup(&tmp[i]);
	}
	return (dst);
}
