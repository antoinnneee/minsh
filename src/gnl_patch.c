#include "../includes/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int				f(char **line, int i)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (i);
}
