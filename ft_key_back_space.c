#include "ft_minishell.h"

void		ft_key_back_space(int *pos)
{
	if (*pos < ft_lstl_len(g_env.cmd))
	{
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
	}
}
