/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 00:39:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 22:13:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_make_history(int *nb_hist, int *dat_i, char *path_h)
{
	char	*line;
	char	**tab;
	int		fd;
	int		i;

	fd = open(path_h, O_CREAT | O_RDWR, 0600);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		(*nb_hist)++;
	}
	close(fd);
	fd = open(path_h, O_CREAT | O_RDONLY);
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (*nb_hist + 1));
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_strdup(line);
		free(line);
		i++;
	}
	tab[i] = NULL;
	close(fd);
	*dat_i = *nb_hist;
	return (tab);
}
