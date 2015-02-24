/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:16:06 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/24 20:09:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBL_H
# define LIBL_H

# include "libft.h"

typedef struct		s_lstl
{
	char			*str;
	struct s_lstl	*next;
}					t_lstl;

t_lstl	*ft_lstl_create(char *str);
size_t	ft_lstl_len(t_lstl *list);
void	ft_lstl_add(t_lstl **begin, char *str);
void	ft_lstl_add_back(t_lstl **begin, char *str);
void	ft_lstl_insert(t_lstl **begin, char *str, size_t pos);
void	ft_lstl_delone(t_lstl **begin, char *str, int (*f)(char const *, char const *));
void	ft_lstl_delone_by_id(t_lstl **begin, size_t id);
void	ft_lstl_print(t_lstl *list);

#endif
