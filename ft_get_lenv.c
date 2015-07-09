/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:28:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/09 05:19:31 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_get_lenv(t_lstl *lenv, const char *var)
{
	char	*dst;
	int		i;

	i = 0;
	while (lenv
		&& !ft_strnequ(var, lenv->str, ft_strlen(var)))
		lenv = lenv->next;
	if (lenv)
	{
		dst = ft_strchr(lenv->str, '=') + 1;
		return (dst);
	}
	return (NULL);
}
