#ifndef INTERPRET_H
# define INTERPRET_H

# include <libft.h>

typedef struct		s_cmd
{
	char			**cmd;
	char			*bin;
	int				type;
	struct s_cmd	*next;
}					t_cmd;



#endif
