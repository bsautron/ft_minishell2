/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:45:19 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/09 23:42:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

#define CHILD		0
#define PARENT		!CHILD


int		ft_exec(char *bin, char **tab, char **env)
{
	pid_t	child;

	child = fork();
	(void)bin;
	(void)tab;
	(void)env;
}
