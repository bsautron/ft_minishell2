/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:28:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/29 14:01:17 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_get_env(char **env, const char *var)
{
	char	*dst;
	int		i;

	i = 0;
	while (env[i]
		&& !ft_strnequ(var, env[i], ft_strlen(var)))
		i++;
	if (env[i])
	{
		dst = ft_strchr(env[i], '=') + 1;
		return (dst);
	}
	return (NULL);
}
