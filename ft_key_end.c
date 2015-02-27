#include "ft_minishell.h"

void		ft_key_end(t_env *env, int *pos)
{
	env = env;
	while ((*pos)--)
		ft_make_instruction("nd", NULL);
	*pos = 0;
}
