/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:18:48 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 12:14:04 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

char			*g_p(char *str, int *j)
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

char			*g_p_n(char *str, int *j)
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
		if (!str[i] || str[i] == ' ' || str[i] == '"')
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

static void		get_o(char **opt, char *commande, int *ind)
{
	if (!*opt)
	{
		*opt = g_p(commande, ind);
		while (commande[*ind] && commande[*ind] != ' ')
		{
			if (commande[*ind] == '"')
				*opt = secure_cat(*opt, g_p(commande, ind), 1);
			else
				*opt = secure_cat(*opt, g_p_n(commande, ind), 1);
		}
	}
	else
	{
		*opt = secure_cat(secure_cat(*opt, ":", 0), g_p(commande, ind), 1);
		while (ft_isalnum(commande[*ind]))
		{
			if (commande[*ind] == '"')
				*opt = secure_cat(*opt, g_p(commande, ind), 1);
			else
				*opt = secure_cat(*opt, g_p_n(commande, ind), 1);
		}
	}
}

char			*get_param(char *com, int *i)
{
	char	*opt;
	int		ind;

	ind = 0;
	opt = NULL;
	while (com[ind])
	{
		if (com[ind] == '"')
			get_o(&opt, com, &ind);
		else if (issymb(com[ind]))
		{
			if (!opt)
				opt = g_p_n(com, &ind);
			else
				opt = secure_cat(secure_cat(opt, ":", 0), g_p_n(com, &ind), 1);
		}
		if (com[ind])
			ind++;
	}
	*i = *i + ind;
	return (opt);
}
