/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:09:46 by abureau           #+#    #+#             */
/*   Updated: 2016/09/12 19:18:31 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_countword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
			{
				while (s[i] == c)
					i++;
			}
			else
			{
				j++;
				while (s[i] != c && s[i])
					i++;
			}
		}
	}
	return (j);
}

static char				**ft_tabfill(char **tab, char const *s, char c)
{
	int i;
	int j;
	int k;

	ft_initthreevar(&i, &j, &k);
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (j > 0)
				k++;
			while (s[i] == c)
				i++;
			j = 0;
		}
		else
		{
			tab[k][j] = s[i];
			i++;
			j++;
		}
	}
	return (tab);
}

static void				ft_ftwin(int *nbl, int *k)
{
	*nbl = 0;
	*k += 1;
}

char					**ft_strsplit(char const *s, char c)
{
	int		var[4];
	char	**tab;

	ft_initthreevar(&var[0], &var[3], &var[2]);
	var[1] = ft_countword(s, c);
	tab = (char**)malloc(sizeof(*tab) * (var[1] + 1));
	if (!tab)
		return (NULL);
	while (var[0] < var[1])
		if (s[var[3]] == c || s[var[3]] == '\0')
		{
			if (var[1] > 0)
			{
				tab[var[0]] = ft_strnew(var[2]);
				ft_ftwin(&var[2], &var[0]);
			}
			while (s[var[3]] == c)
				ft_ftwin(&var[2], &var[3]);
		}
		else
			ft_inctwovar(&var[2], &var[3]);
	tab[var[1]] = NULL;
	tab = ft_tabfill(tab, s, c);
	return (tab);
}
