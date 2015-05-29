/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 11:30:43 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/29 11:36:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_lstl   *ft_get_var_env(char **env)
{
	t_lstl  *lenv;
	int     i;

	i = 0;
	lenv = NULL;
	while (env[i])
	{
		ft_lstl_add_back(&lenv, env[i]);
		i++;
	}
	return (lenv);
}
