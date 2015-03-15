#include "ft_minishell.h"

void		ft_key_end(int *pos)
{
	while ((*pos)--)
		ft_make_instruction("nd", NULL);
	*pos = 0;
}
