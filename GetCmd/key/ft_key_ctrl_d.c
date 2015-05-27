#include "ft_minishell.h"

void		ft_key_ctrl_d(int *pos)
{
	if (ft_lstl_len(g_env.cmd) == 0)
	{
		ft_reset_term();
		ft_lstl_free(&g_env.list_env);
		ft_putchar('\n');
		exit(0);
	}
	else
	{
		ft_make_instruction("dc", NULL);
		if (*pos)
		{
			(*pos)--;
			ft_lstl_delone_by_id(&g_env.cmd, *pos);
		}
	}
}
