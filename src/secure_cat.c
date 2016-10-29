#include "../libft/includes/libft.h"

char	*secure_cat(char *dest, char *str, int state)
{
	char	*mstr;
	int	llen;

	llen = ft_strlen(str) + ft_strlen(dest);
	mstr = (char*) ft_memalloc(sizeof(char) * llen + 1);
	ft_strcpy(mstr, dest);
	ft_strcpy(&mstr[ft_strlen(mstr)], str);
	if (dest)
		ft_strdel(&dest);
	if (state)
		if (str)
		ft_strdel(&str);
	mstr[llen] = '\0';
	return (mstr);	
}

