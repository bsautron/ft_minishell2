/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 12:27:57 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 12:33:22 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>
# include <stdlib.h>
# include <token.h>
# include <btree.h>
# include <stdio.h>//////////////

# define LEFT	0
# define RIGHT	1

# define INFIXE		1
# define SUFIXE		2
# define POSTFIXE	3

t_btree			*parse(t_token *tk_list);

#endif
