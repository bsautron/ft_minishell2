/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbultin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 04:25:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 04:28:11 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_isbultin(char *cmd)
{
	if (ft_strequ(cmd, "exit")
			|| ft_strequ(cmd, "env")
			|| ft_strequ(cmd, "cd")
			|| ft_strequ(cmd, "pwd")
			|| ft_strequ(cmd, "setenv")
			|| ft_strequ(cmd, "unsetenv"))
		return (1);
	return (0);
}
