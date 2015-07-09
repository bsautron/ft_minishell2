/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 05:10:04 by bsautron          #+#    #+#             */
/*   Updated: 2015/07/09 05:50:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <libft.h>
# include <libl.h>
# include <libld.h>
# include <sys/ioctl.h>
# include <getcmd.h>
# include <lexer_parser.h>
# include <interpret.h>
# include <bultins.h>

t_lstl	*ft_get_var_env(char **env);
char	*ft_get_env(char **env, char const *var);
char	*ft_get_lenv(t_lstl *lenv, char const *var);
void	ft_attrape_moi_si_tu_peux(void);
void	ft_signal_handler(int sig);
char	**ft_tk_to_tab(t_token *list);
char	**ft_lstl_to_tab(t_lstl *list);

int		ft_exec_tree(t_btree *tree, t_lstl **lenv);
int		ft_interpret(t_token *tk, t_lstl **lenv);

#endif
