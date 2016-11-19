#include "../libft/includes/libft.h"

int issymb(const char c)
{
	if (ft_isalnum(c))
		return (1);
	if (c > 34 && c < 47)
		return (1);
	if (c  == 95)
		return (1);
	if (c == '/')
		return (1);
	return (0);
}
