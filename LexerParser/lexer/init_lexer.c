/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 00:08:46 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/16 13:11:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void		init_state_flow(t_lexer *lexer)
{
	lexer->state_flows = (t_state_flow*)malloc(sizeof(t_state_flow) *
		NB_STATE_FLOWS);
	lexer->state_flows[STATE_DEFAULT] = default_state_flow;
	lexer->state_flows[STATE_INHB_CMD_ARG] = inhb_cmd_arg_state_flow;
	lexer->state_flows[STATE_CMD_ARG] = cmd_arg_state_flow;
	lexer->state_flows[STATE_AND_OPERATOR] = and_operator_state_flow;
	lexer->state_flows[STATE_OR_OPERATOR] = or_operator_state_flow;
	lexer->state_flows[STATE_SUBCOMMAND] = subcommand_state_flow;
	lexer->state_flows[STATE_BACKSLASH] = backslash_state_flow;
}

t_lexer			*init_lexer(char *str)
{
	t_lexer		*lexer;

	lexer = (t_lexer*)malloc(sizeof(t_lexer));
	lexer->str = str;
	lexer->pos = 0;
	lexer->token_length = 0;
	lexer->depth = 0;
	push_state(STATE_DEFAULT, lexer);
	init_state_flow(lexer);
	return (lexer);
}
