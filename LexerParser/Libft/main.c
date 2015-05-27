/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 23:56:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/10 00:01:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stdio.h>
int			main(int ac, char **av)
{
	char	**tab;

	if (ac < 3)
		return (0);
	tab = ft_strsplit(av[1], av[2][0]);
	while (*tab)
	{
		printf("%s\n", *tab);
		tab++;
	}
	return (0);
}
