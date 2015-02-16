/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 07:58:27 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/11 08:33:38 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_nbenv(char **env)
{
	int		i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

static char	**ft_realloc_env(char **env, int id)
{
	int		i;
	int		j;
	int		nb_env;
	char	**new_env;

	i = 0;
	nb_env = ft_nbenv(env);
	new_env = (char **)malloc(sizeof(char *) * (nb_env + 1));
	while (env[i] && i < id)
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	j = i;
	i++;
	while (env[i])
	{
		new_env[j] = ft_strdup(env[i]);
		i++;
		j++;
	}
	new_env[j] = NULL;
	i = 0;
	return (new_env);
}

int			ft_unsetenv(char ***env, char *del)
{
	int		id;
	int		nb_env;

	id = 0;
	nb_env = ft_nbenv(*env);
	if (ft_onlyesp(del))
	{
		ft_putendl("unset: not enought arguments");
		return (0);
	}
	dprintf(1, "%s\n", "avant");
	del = ft_strtrim_new(del);
	while (del && *del)
	{
		while (*del && *del <= ' ')
			del++;
		while ((*env)[id] && !ft_strnequ((*env)[id],
					ft_strjoin(ft_getcmd(del), "="), ft_strlen_esp(del) + 1))
			id++;
	dprintf(1, "%s\n", "apres");
		if (id < nb_env)
			*env = ft_realloc_env(*env, id);
		del += ft_strlen_esp(del);
	}
	return (0);
}
