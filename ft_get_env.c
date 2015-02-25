/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:28:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 10:34:20 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_get_env(char *var, t_lstl *env)
{
	while (env && !ft_strnequ(var, env->str, ft_strlen(var)))
		env = env->next;
	if (env)
		return (ft_strchr(env->str, '=') + 1);
	return (NULL);
}
