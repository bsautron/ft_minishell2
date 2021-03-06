/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 05:07:34 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/09 05:54:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRET_H
# define INTERPRET_H

# include <libft.h>
# include <libl.h>

typedef struct		s_cmd
{
	char			**cmd;
	char			*bin;
	int				type;
	struct s_cmd	*next;
}					t_cmd;

t_cmd	*ft_cmd_create(char ***cmd, char **bin, int type);
void	ft_cmd_add(t_cmd **begin, t_cmd *cmd);
void	ft_cmd_add_back(t_cmd **begin, t_cmd *cmd);
void	ft_exec_bultin(t_cmd *cmd, t_lstl **lenv);

#endif
