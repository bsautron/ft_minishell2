#include "ft_minishell.h"

static void	ft_putstr_spec(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		ft_putchar(str[i]);
		if (g_env.nb_line == 0 && i + 1 + ft_strlen("DatPrompt> ") == g_env.win_col - 1)
		{
			ft_make_instruction("do", NULL);
			g_env.nb_line++;
		}
		else if ((i + 1 + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
		{
			ft_make_instruction("do", NULL);
			g_env.nb_line++;
		}
		i++;
	}
}

void		ft_key_up(int *pos)
{
	if (g_env.h_pos == 0)
	{
		g_env.nb_line = 0;
		g_env.cmd_saved = g_env.cmd;
	}
	if (g_env.h_pos < ft_lstld_len(g_env.history))
	{
		g_env.nb_line = 0;
		ft_key_home(pos);
		ft_make_instruction("ei", NULL);
		ft_make_instruction("cd", NULL);
		ft_putstr_spec(ft_get_link_by_id(g_env.history, g_env.h_pos)->str);
		g_env.cmd = ft_str_to_lstl(
				ft_get_link_by_id(g_env.history, g_env.h_pos)->str);
		*pos = 0;
		g_env.h_pos++;
	}
}
