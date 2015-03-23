#include "ft_minishell.h"

void		ft_key_up(int *pos)
{
	if (g_env.h_pos == 0)
	{
		g_env.nb_line = 0;
		g_env.cmd_saved = g_env.cmd;
	}
	if (g_env.h_pos < ft_lstld_len(g_env.history))
	{
		ft_key_home(pos);
		g_env.nb_line = 0;
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_get_link_by_id(g_env.history, g_env.h_pos)->str);
		g_env.cmd = ft_str_to_lstl(
				ft_get_link_by_id(g_env.history, g_env.h_pos)->str);
		*pos = 0;
		g_env.h_pos++;
	}
}
