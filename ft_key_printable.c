#include "ft_minishell.h"

void		ft_key_printable(char *buf, int *pos)
{
	ft_putchar(buf[0]);
	g_env.h_pos = 0;
	ft_lstl_insert(&g_env.cmd, buf, *pos);
}
