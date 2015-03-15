/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:28:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 13:21:58 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_get_env(char *var)
{
	while (g_env.list_env
		&& !ft_strnequ(var, g_env.list_env->str, ft_strlen(var)))
		g_env.list_env = g_env.list_env->next;
	if (g_env.list_env)
		return (ft_strchr(g_env.list_env->str, '=') + 1);
	return (NULL);
}
