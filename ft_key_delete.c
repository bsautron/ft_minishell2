#include "ft_minishell.h"

void		ft_key_delete(int *pos)
{
	ft_make_instruction("dc", NULL);
	if (*pos)
	{
		(*pos)--;
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
	}
}
