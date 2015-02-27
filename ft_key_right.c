#include "ft_minishell.h"

void		ft_key_right(t_env *env, int *pos)
{
	env = env;
	if (*pos != 0)
	{
		(*pos)--;
		ft_make_instruction("nd", NULL);
	}
	if (*pos == 0)
		ft_make_instruction("ei", NULL);
}
