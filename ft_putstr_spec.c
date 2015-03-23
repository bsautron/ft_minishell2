#include "ft_minishell.h"

void	ft_putstr_spec(char *str)
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
