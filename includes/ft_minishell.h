/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 02:01:20 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdio.h>//
# include <termios.h>
# include "libft.h"
# include "libl.h"

void	ft_tcg(char f);
int		ft_outc(int c);
void	ft_make_instruction(char *id, char *area);
void	ft_prompt(t_lstl *env);
void	ft_signal_handler(int sig);

#endif

