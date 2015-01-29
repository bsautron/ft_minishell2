/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dirname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 00:35:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 22:25:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_get_dirname(void)
{
	char	*path;
	char	*dst;
	int		len;

	path = ft_pwd();
	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	if (!path[len - 1])
	{
		dst = ft_strdup(path + len);
		free(path);
		return (dst);
	}
	dst = ft_strdup(path + len + 1);
	free(path);
	return (dst);
}
