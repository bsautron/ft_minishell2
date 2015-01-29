/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prev_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:24:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 03:08:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_get_prev_dir(char *path)
{
	int		i;

	i = ft_strlen(path) - 1;
	while (path[i] && path[i] != '/')
	{
		path[i] = '\0';
		i--;
	}
	return (path);
}
