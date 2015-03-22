#include "ft_minishell.h"

void		ft_key_back_space(int *pos)
{
	if (*pos < ft_lstl_len(g_env.cmd))
	{
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
		ft_lstl_delone_by_id(&g_env.cmd, *pos);
	}
	if (ft_lstl_len(g_env.cmd) % (g_env.win_col - 2) == 0)
	{
		ft_make_instruction("up", NULL);
		g_env.nb_line--;
		ft_putstr("\033[");
		ft_putstr(ft_itoa(g_env.win_col));
		ft_putstr("C");
		ft_make_instruction("le", NULL);
		ft_make_instruction("dc", NULL);
	}
}
