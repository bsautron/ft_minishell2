/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scope_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 18:45:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/25 18:48:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

void	ft_scope_cursh(char c)
{
	if (c == '}')
		ft_scope_pop(&g_env.scope);
	if (c == '{')
		ft_scope_push(&g_env.scope, SCOPE_CURSH);
	if (c == '"')
		ft_scope_push(&g_env.scope, SCOPE_DQUOTE);
	if (c == '\'')
		ft_scope_push(&g_env.scope, SCOPE_QUOTE);
	if (c == '`')
		ft_scope_push(&g_env.scope, SCOPE_BQUOTE);
	if (c == '(')
		ft_scope_push(&g_env.scope, SCOPE_SUBSH);
}
