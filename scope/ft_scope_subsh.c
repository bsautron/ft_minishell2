/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 18:45:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/25 18:49:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_scope_subsh(char c)
{
	if (c == ')')
		ft_scope_pop(&g_env.scope);
	if (c == '(')
		ft_scope_push(&g_env.scope, SCOPE_SUBSH);
	if (c == '"')
		ft_scope_push(&g_env.scope, SCOPE_DQUOTE);
	if (c == '\'')
		ft_scope_push(&g_env.scope, SCOPE_QUOTE);
	if (c == '`')
		ft_scope_push(&g_env.scope, SCOPE_BQUOTE);
	if (c == '{')
		ft_scope_push(&g_env.scope, SCOPE_CURSH);
}
