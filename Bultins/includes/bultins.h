/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 05:02:57 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/09 07:17:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

# include <libft.h>
# include <interpret.h>

# define NB_BULTINS		3
# define PWD			"pwd"
# define ENV			"env"
# define SETENV			"setenv"

enum		e_bultin
{
	TB_DEFAULT = 0,
	TB_PWD,
	TB_ENV,
	/*------No Fork-----*/
	TB_NOFORK,
	TB_SETENV
};

char    *ft_pwd(void);
void    ft_setenv(t_lstl **lenv, t_cmd *cmd);
void	ft_env(t_lstl **lenv, t_cmd *cmd);

#endif
