#include "ft_minishell.h"

void		ft_key_home(int *pos)
{
	int		i;
	int		flag;

	flag = 0;

	if (*pos < g_env.win_col - 1)
	{
		i = g_env.nb_line;
		while (i > 0)
		{
			*pos += (g_env.win_col - 1);
			i--;
			ft_make_instruction("up", NULL);
		}
	}
	if (flag == 0)
	{
		while ((*pos)++ < ft_lstl_len(g_env.cmd))
			ft_make_instruction("le", NULL);
	}
	*pos = ft_lstl_len(g_env.cmd);
	ft_make_instruction("im", NULL);
}
