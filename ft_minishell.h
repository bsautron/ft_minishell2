/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:22:51 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/09 06:01:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

#include <stdio.h>///////

# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>
# include "libft.h"
# include "get_next_line.h"

# define FLECHE	ft_putchar(-30);ft_putchar(-98);ft_putchar(-100);ft_putchar(' ')
# define CATCH_SIG	signal(SIGINT, ft_stop);if (g_stop == 1)kill(child, SIGINT);\
	g_stop = 0
# define IS_CHILD(x)	((x == 0) ? 1 : 0)

extern int		g_stop;

char	*ft_prompt(char **env, int ret);
void	ft_stop(int sig);
void	ft_disable_sig(void);
char	**ft_getpath(char **env);
char	*ft_getabsolute_path(char *cmd, char **env, char say_error);
char	*ft_getdir(char *path);
char	*ft_getpath_pwd(char *path);
char	*ft_getcmd(char *cmd);
char	*ft_get_prev_dir(char *path);
int		ft_get_id_var(char **env, char *var);
int		ft_env(char ***env, char *after, int rt);
int		ft_cmd(char **env);
int		ft_cd(char ***env, char *path);
char	ft_onlyesp(char *str);
char	*ft_pwd(void);
int		ft_setenv(char ***env, char *xport);
int		ft_unsetenv(char ***env, char *xport);
int		ft_cmd_is_in_path(char *cmd, char *path);
char	**ft_strsplit_white_space(char const *s);
char	**ft_strsplit_whitespace(char const *s);
char	**ft_strsplit_str(char const *s, char *c);
int		ft_exec(char *cmd, char **env);
int		ft_nb_env(char **env);
int		ft_nbargv(char *str);
int		ft_error_cd(char **env, char **tab, char *path);
int		ft_not_dir(char **tab, char *d_path);
char	*ft_strtrim_new(char const *s);
int		ft_what(char *cmd, char ***env, int rt);
char	*ft_get_dirname(void);
void	ft_nclear(size_t n);
char	**ft_make_history(int *nb_hist, int *dat_i, char *path_h);
char	*ft_join_or_del(char *cmd, char *c, char cac, int *pos);
int		ft_isbultin(char *cmd);
void	ft_tcg(char f);

char	ft_first_redir(char *cmd);
void	ft_runpipe(char *cmd, char **env);
void	ft_runsup(char *cmd, char **env, char flag);
void	ft_runinf(char *cmd, char **env);
void	ft_rundoublesup(char *cmd, char **env);

#endif
