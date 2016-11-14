#include "../includes/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

int				f(char **line, int i)
{
	static char	**tmp;
	if (i)
	{
	ft_putendl("free");
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	else
		tmp = line;
	return (i);
}

int				fb(char ***line, int i)
{
	static char	***tmp;

	if (i)
	{
	ft_putendl("free");
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	else
		tmp = line;
	return (i);
}
