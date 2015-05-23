/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:16:06 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/25 15:32:29 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLD_H
# define LIBLD_H

# include "libft.h"

typedef struct		s_lstld
{
	char			*str;
	struct s_lstld	*next;
	struct s_lstld	*prev;
}					t_lstld;

t_lstld	*ft_lstld_create(char *str);
int		ft_lstld_len(t_lstld *list);
void	ft_lstld_add(t_lstld **begin, char *str);
void	ft_lstld_print(t_lstld *list);
void	ft_lstld_free(t_lstld **begin);

#endif
