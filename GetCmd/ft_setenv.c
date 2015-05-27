/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:59:57 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:04:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_get_var(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_strsub(str, 0, i));
}

void	ft_setenv(t_env *env, char *str)
{
	t_lstl	*tmp;
	char	*var;
	size_t	i;

	tmp = env->list_env;
	i = 0;
	var = ft_strjoin(ft_get_var(str), "=");
	while (tmp && !ft_strnequ(var, tmp->str, ft_strlen(var)))
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp)
	{	
		free(tmp->str);
		tmp->str = ft_strdup(str);
	}
	else
		ft_lstl_add_back(&env->list_env, str);
}
