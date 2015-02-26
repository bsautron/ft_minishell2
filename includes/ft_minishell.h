/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/26 03:46:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "libft.h"
# include "libl.h"
# include "libld.h"
# include <stdio.h>
# include <termios.h>
# include <term.h>

# define HISTORY_FILE	"/.ft_minishell_history"

typedef struct		s_env
{
	t_lstl			*list_env;
	t_lstl			*cmd;
	t_lstl			*cmd_saved;
	t_lstld			*history;
	size_t			h_pos;
	char			*path_h;
	int				ret;
}					t_env;

void	ft_tcg(t_env *env);
void	ft_reset_term(void);
void	ft_setenv(t_env *env, char *str);
char	*ft_pwd(void);
char	*ft_get_env(char *var, t_env *env);
int		ft_onlyesp(char *str);
char	*ft_parser(char *cmd, t_env *env);
char	*ft_replace(char *src, char *str1, char *str2, int pos);
int		ft_outc(int c);
void	ft_make_instruction(char *id, char *area);
char	*ft_prompt(t_env *env);
void	ft_signal_handler(int sig);

#endif
