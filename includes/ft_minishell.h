/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/26 05:13:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "libft.h"
# include "libl.h"
# include "libld.h"
# include <stdio.h>
# include <fcntl.h>
# include <termios.h>
# include <term.h>

# define KEY_CTRL_D		"\x04\0\0\0\0\0\0"
# define KEY_UP			"\x1b\x5b\x41\0\0\0\0"
# define KEY_DOWN		"\x1b\x5b\x42\0\0\0\0"
# define KEY_RIGHT		"\x1b\x5b\x43\0\0\0\0"
# define KEY_LEFT		"\x1b\x5b\x44\0\0\0\0"
# define KEY_BACK_SPACE	"\x7f\0\0\0\0\0\0"
# define KEY_DELETE		"\x1b\x5b\x33\x7e\0\0\0"
# define KEY_END		"\x1b\x5b\x46\0\0\0\0"
# define KEY_HOME		"\x1b\x5b\x48\0\0\0\0"

# define HISTORY_FILE	"/.ft_minishell_history"
# define HISTORY_LIMITS	10000

typedef struct s_env	t_env;
typedef struct s_key	t_key;

struct		s_key
{
	char	*tab_key[11];
	void	(*f[11])(t_env *, int *);
};

struct		s_env
{
	char			*name_term;
	t_lstl			*list_env;
	t_lstl			*cmd;
	t_lstl			*cmd_saved;
	t_lstld			*history;
	int				h_pos;
	char			*path_h;
	int				ret;
};

void	ft_set_term(t_env *env);
void	ft_reset_term(void);
void	ft_setenv(t_env *env, char *str);
char	*ft_pwd(void);
char	*ft_get_env(char *var, t_env env);
int		ft_onlyesp(char *str);
char	*ft_parser(char *cmd, t_env *env);
char	*ft_replace(char *src, char *str1, char *str2, int pos);
int		ft_outc(int c);
void	ft_make_instruction(char *id, char *area);
char	*ft_prompt(t_env *env);
void	ft_signal_handler(int sig);
t_lstld	*ft_get_link_by_id(t_lstld *list, size_t id);
void	ft_print_list_char(t_lstl *cmd);
char	*ft_lstl_to_str(t_lstl *list);
t_lstl	*ft_str_to_lstl(char *str);

void	ft_key_ctrl_d(t_env *env, int *pos);
void	ft_key_back_space(t_env *env, int *pos);
void	ft_key_delete(t_env *env, int *pos);
void	ft_key_down(t_env *env, int *pos);
void	ft_key_end(t_env *env, int *pos);
void	ft_key_home(t_env *env, int *pos);
void	ft_key_left(t_env *env, int *pos);
void	ft_key_printable(t_env *env, char *buf, int *pos);
void	ft_key_right(t_env *env, int *pos);
void	ft_key_up(t_env *env, int *pos);

#endif
