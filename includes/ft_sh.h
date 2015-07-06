#ifndef FT_SH_H
# define FT_SH_H

# include <libft.h>
# include <libl.h>
# include <libld.h>
# include <sys/ioctl.h>
# include <getcmd.h>
# include <lexer_parser.h>

t_lstl	*ft_get_var_env(char **env);
char	*ft_get_env(char **env, char const *var);
void	ft_attrape_moi_si_tu_peux(void);
void	ft_signal_handler(int sig);
char	**ft_tk_to_tab(t_token *list);
char	**ft_lstl_to_tab(t_lstl *list);

int		ft_exec_tree(t_btree *tree, t_lstl *env);
int		ft_exec(t_token *tk, char **env);

char	*ft_pwd(void);
void	ft_setenv(t_lstl **env, char *str);

#endif
