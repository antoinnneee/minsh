#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

char	*g_p(char *str, int *j)
{
	int	i;
	int	beg;

	beg = *j;
	i = *j;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			beg = i;
			while (str[i] && str[i] != '"')
			{
				i++;
			}
			if (str[i] == '"')
			{
				*j = i + 1;
				return (ft_strsub(str, beg, i - beg));
			}
		}
		if (str[i])
			i++;
	}
	return (NULL);
}

char	*g_p_n(char *str, int *j)
{
	int	i;
	int	beg;

	beg = *j;
	i = *j;
	while (str[i])
	{
		beg = i;
		while (str[i] && str[i] != ' ' && str[i] != '"')
		{
			i++;
		}
		if (!str[i]  || str[i] == ' ' || str[i] == '"')
		{
			*j = i;
			return (ft_strsub(str, beg, i - beg));
		}
		if (str[i])
			i++;
	}
	*j = i;
	return (NULL);
}

static void		get_o(char **option, char *commande, int *ind)
{
	if (!*option)
	{
		*option = g_p(commande, ind);
		while (commande[*ind] && commande[*ind] != ' ')
		{
			if (commande[*ind] == '"')
				*option = secure_cat(*option, g_p(commande, ind), 1);
			else
				*option = secure_cat(*option, g_p_n(commande, ind), 1);
		}
	}
	else
	{
		*option = secure_cat(secure_cat(*option, ":", 0), g_p(commande, ind), 1);
		while (ft_isalnum(commande[*ind]))
		{
			if (commande[*ind] == '"')
				*option = secure_cat(*option, g_p(commande, ind), 1);
			else
				*option = secure_cat(*option, g_p_n(commande, ind), 1);
		}
	}
}

char			*get_param(char *commande, int *i)
{
	char	*option;
	int		ind;
	
	ind = 0;
	option = NULL;
	while (commande[ind])
	{
		if (commande[ind] == '"')
			get_o(&option, commande, &ind);
		else if (issymb(commande[ind]))
		{
			if (!option)
				option = g_p_n(commande, &ind);
			else
				option = secure_cat(secure_cat(option, ":", 0), g_p_n(commande, &ind), 1);
		}
		if (commande[ind])
			ind++;
	}
	*i = *i + ind;
	return (option);
}

