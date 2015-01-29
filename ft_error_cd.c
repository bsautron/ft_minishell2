/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:27:53 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 03:07:20 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_error_cd(char **env, char **tab, char *path)
{
	int			id;

	id = ft_get_id_var(env, "PWD");
	if (ft_onlyesp(path))
		return (0);
	if (id == -1)
		return (0);
	if (ft_nb_env(tab) > 1)
	{
		if (ft_nb_env(tab) > 2)
		{
			ft_putendl_fd("cd: too many arguments", 2);
			return (-1);
		}
		else if (!ft_strequ(ft_strstr(ft_pwd(), tab[0]),
					tab[0]))
		{
			ft_putstr_fd("cd: string not in pwd: ", 2);
			ft_putendl_fd(tab[0], 2);
			return (-1);
		}
	}
	return (0);
}
