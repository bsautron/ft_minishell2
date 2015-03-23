#include "ft_minishell.h"

void		ft_key_down(int *pos)
{
	g_env.h_pos--;
	if (g_env.h_pos > 0)
	{
		ft_key_home(pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_get_link_by_id(g_env.history, g_env.h_pos - 1)->str);
		g_env.cmd = ft_str_to_lstl(
				ft_get_link_by_id(g_env.history, g_env.h_pos - 1)->str);
		*pos = 0;
	}
	else if (g_env.h_pos == 0)
	{
		ft_key_home(pos);
		g_env.cmd = g_env.cmd_saved;
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_print_list_char(g_env.cmd);
		*pos = 0;
	}
	else
		g_env.h_pos = 0;
}
