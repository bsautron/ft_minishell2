#include "ft_minishell.h"

void		ft_key_printable(char *buf, int *pos)
{
	ft_putchar(buf[0]);
	g_env.h_pos = 0;
	ft_lstl_insert(&g_env.cmd, buf, *pos);
	if (g_env.nb_line == 0 && ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ") == g_env.win_col - 1)
	{
		ft_make_instruction("do", NULL);
		g_env.nb_line++;
	}
	else if ((ft_lstl_len(g_env.cmd) - *pos + ft_strlen("DatPrompt> ")) % (g_env.win_col - 1) == 0)
	{
		ft_make_instruction("do", NULL);
		g_env.nb_line++;
	}
}
