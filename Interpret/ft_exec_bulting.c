/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bulting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 05:00:19 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/09 07:18:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void		ft_exec_bultin(t_cmd *cmd, t_lstl **lenv)
{
	if (cmd->type == TB_PWD)
		ft_putendl(ft_pwd());
	else if (cmd->type == TB_SETENV)
		ft_setenv(lenv, cmd);
	else if (cmd->type == TB_ENV)
		ft_env(lenv, cmd);
}
