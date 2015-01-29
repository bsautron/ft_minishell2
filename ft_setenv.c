/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 06:22:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 12:40:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_pos_eq(char *xport)
{
	int		i;

	i = 0;
	while (xport[i])
	{
		if (xport[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	**ft_realloc_env(char **env, char *xport)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(xport);
	new_env[i + 1] = NULL;
	return (new_env);
}

int			ft_setenv(char ***env, char *xport)
{
	int		eq;
	int		id;
	char	*deb;
	char	*fin;

	xport = ft_strtrim(xport);
	while (xport && *xport)
	{
		while (*xport <= ' ')
			xport++;
		if ((eq = ft_pos_eq(xport)) == -1)
			return (0);
		if ((id = ft_get_id_var(*env, ft_strsub(xport, 0, eq + 1))) != -1)
		{
			deb = ft_strsub(xport, 0, eq + 1);
			fin = ft_strsub(xport, eq + 1, ft_strlen_esp(xport + eq + 1));
			(*env)[id] = ft_strjoin(deb, fin);
			free(deb);
			free(fin);
		}
		else
		{
			*env = ft_realloc_env(*env,
					ft_strndup(xport, ft_strlen_esp(xport)));
		}
		xport += ft_strlen_esp(xport);
	}
	return (0);
}
