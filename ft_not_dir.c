/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:29:40 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 03:10:09 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_make_second(char **tab)
{
	int		i;
	int		j;
	char	*pwd;

	pwd = ft_pwd();
	i = ft_strlen(pwd) - 1;
	j = ft_strlen(tab[0]) - 1;
	while (i >= 0 && pwd[i] == tab[0][j])
	{
		pwd[i] = '\0';
		i--;
		j--;
	}
	tab[1] = ft_strjoin(pwd, tab[1]);
}

static int	ft_denied(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == 0 && S_ISDIR(buf.st_mode) && opendir(path) == NULL)
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(path, 2);
		return (-1);
	}
	return (0);
}

static int	ft_not_d(char *path)
{
	ft_putstr_fd("cd: Not a directory :", 2);
	ft_putendl_fd(path, 2);
	return (-1);
}

static int	ft_not_ford(char *path)
{
	ft_putstr_fd("cd: No such file or directory: ", 2);
	ft_putendl_fd(path, 2);
	return (-1);
}

int			ft_not_dir(char **tab, char *d_path)
{
	struct stat		buf;
	char			*path;

	path = tab[0];
	if (!ft_onlyesp(d_path) && ft_nb_env(tab) > 1)
	{
		ft_make_second(tab);
		path = tab[1];
	}
	if (ft_denied(path) == -1)
		return (-1);
	if (ft_strequ(path, "-") || ft_strequ(path, "--") || ft_strequ(path, "~"))
		return (0);
	if (lstat(path, &buf) == 0 &&
			!S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
		return (ft_not_d(path));
	else if (lstat(path, &buf))
		return (ft_not_ford(path));
	return (0);
}
