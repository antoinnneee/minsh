#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	run_pwd(t_cmd *cmd, t_msh *msh)
{
	char *re;

	re  = ft_memalloc((sizeof(char) * 256));
	re = getcwd(re, 256);
	if (re)
	{
		ft_putendl(re);
		free(re);
	}
}

