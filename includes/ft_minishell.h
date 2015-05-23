/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/23 18:47:48 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "libft.h"
# include "libl.h"
# include "libld.h"
# include <scope.h>
# include <sys/ioctl.h>
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
# define KEY_ALT_UP		"\x1b\x1b\x5b\x41\0\0\0"
# define KEY_ALT_DOWN	"\x1b\x1b\x5b\x42\0\0\0"
# define KEY_ALT_RIGHT	"\x1b\x1b\x5b\x43\0\0\0"
# define KEY_ALT_LEFT	"\x1b\x1b\x5b\x44\0\0\0"
# define KEY_CTRL_B		"\x2\0\0\0\0\0\0"			//copier avant le curseur
# define KEY_CTRL_N		"\xe\0\0\0\0\0\0"			//copier apres le curseur
# define KEY_CTRL_B1	"\x1b\0\0\0\0\0\0"			//couper avant le curseur
# define KEY_CTRL_B2	"\x1d\0\0\0\0\0\0"			//couper apres le curseur
# define KEY_CTRL_W		"\x18\0\0\0\0\0\0"			//couper un mot

# define HISTORY_FILE	"/.ft_minishell_history"
# define HISTORY_LIMITS	10000

# define NB_KEY_SPEC	15

typedef struct s_env	t_env;
typedef struct s_key	t_key;
typedef enum e_escope	t_escope;

enum		e_escope
{
	SCOPE_DEFAULT,
	SCOPE_QUOTE,
	SCOPE_BQUOTE,
	SCOPE_DQUOTE,
	SCOPE_CURSH,
	SCOPE_SUBSH,
	SCOPE_HOOK
};

struct		s_key
{
	char	*tab_key[NB_KEY_SPEC];
	void	(*f[NB_KEY_SPEC])(int *);
};

struct		s_env
{
	char			*name_term;
	t_lstl			*list_env;
	t_lstl			*cmd;
	t_lstl			*cmd_returned;
	t_lstl			*cmd_saved;
	char			*prompt;
	int				pos;
	t_lstld			*history;
	int				h_pos;
	char			*path_h;
	int				ret;
	int				win_col;
	t_scope			*scope;
};

extern t_env			g_env;

void	ft_set_term(void);
void	ft_reset_term(void);
void	ft_setenv(t_env *env, char *str);
char	*ft_pwd(void);
char	*ft_get_env(char *var);
int		ft_onlyesp(char *str);
void	ft_move_cursor(int pos);
char	*ft_parser(char *cmd);
char	*ft_replace(char *src, char *str1, char *str2, int pos);
int		ft_outc(int c);
char	*ft_get_dirname(void);
void	ft_make_instruction(char *id, char *area);
void	ft_putstr_spec(char *str);
char	*ft_get_cmd(void);
void	ft_signal_handler(int sig);
t_lstl	*ft_lstl_get_link_by_id(t_lstl *list, size_t id);
t_lstld	*ft_lstld_get_link_by_id(t_lstld *list, size_t id);
void	ft_print_list_char(t_lstl *cmd);
char	*ft_lstl_to_str(t_lstl *list);
t_lstl	*ft_str_to_lstl(char *str);
void	ft_refresh(void);

void	ft_key_printable(char *buf, int *pos);
void	ft_key_ctrl_d(int *pos);
void	ft_key_back_space(int *pos);
void	ft_key_delete(int *pos);
void	ft_key_down(int *pos);
void	ft_key_end(int *pos);
void	ft_key_home(int *pos);
void	ft_key_left(int *pos);
void	ft_key_right(int *pos);
void	ft_key_up(int *pos);
void	ft_key_alt_right(int *pos);
void	ft_key_alt_left(int *pos);
void	ft_key_alt_up(int *pos);
void	ft_key_alt_down(int *pos);
void	ft_key_ctrl_v(char *buf, int *pos);

#endif
