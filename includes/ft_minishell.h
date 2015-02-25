/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:07:16 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "libft.h"
# include "libl.h"
# include <stdio.h>
# include <termios.h>
# include <term.h>

# define HISTORY_FILE	"/.ft_minishell_history"

typedef struct		s_env
{
	t_lstl			*list_env;
	char			*path_h;
	t_lstld			*history;
	int				ret;
}					t_env;

void	ft_tcg(t_env *env);
void	ft_reset_term(void);
void	ft_setenv(t_env *env, char *str);
char	*ft_pwd(void);
char	*ft_get_env(char *var, t_env *env);
char	*ft_parser(char *cmd, t_env *env);
char	*ft_replace(char *src, char *str1, char *str2, int pos);
int		ft_outc(int c);
void	ft_make_instruction(char *id, char *area);
char	*ft_prompt(t_env *env);
void	ft_signal_handler(int sig);

#endif

