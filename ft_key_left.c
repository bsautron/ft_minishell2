#include "ft_minishell.h"

void		ft_key_left(int *pos)
{
	if (*pos < ft_lstl_len(g_env.cmd))
	{
		(*pos)++;
		ft_make_instruction("le", NULL);
		ft_make_instruction("im", NULL);
	}
}
