/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 18:31:26 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/25 18:50:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPE_H
# define SCOPE_H

# include <libft.h>

typedef struct s_scope		t_scope;

struct		s_scope
{
	int				id;
	struct s_scope	*next;
};

void	ft_scope_free(t_scope **begin);
int		ft_scope_len(t_scope *list);
t_scope	*ft_scope_create(int id);
void	ft_scope_print(t_scope *list);
void	ft_scope_push(t_scope **begin, int id);
void	ft_scope_default(char c);
void	ft_scope_quote(char c);
void	ft_scope_bquote(char c);
void	ft_scope_dquote(char c);
void	ft_scope_cursh(char c);
void	ft_scope_subsh(char c);
void	ft_scope_hook(char c);

#endif

