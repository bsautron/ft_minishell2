#include "ft_minishell.h"


static void	ft_attention_a_toi_mec_ne_me_met_pas_zero_stp(t_env *env, struct termios *term)
{
	if ((env->name_term = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("env NULL getenv Failed", 2);
		exit(1);
	}
	if (tgetent(NULL, env->name_term) == -1)
	{
		ft_putendl_fd("env NULL tgetent Failed", 2);
		exit(1);
	}
	if (tcgetattr(0, term) == -1)
	{
		ft_putendl_fd("tcgetattr Failed", 2);
		exit(1);
	}
}

void		ft_set_term(t_env *env)
{
	struct termios	term;

	ft_attention_a_toi_mec_ne_me_met_pas_zero_stp(env, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
	{
		ft_putendl_fd("tcsetattr Failed", 2);
		exit(1);
	}
}
