/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:51:37 by abureau           #+#    #+#             */
/*   Updated: 2015/12/05 14:53:40 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrimchar(char const *s, char c)
{
	int		len;
	int		i;
	int		j;
	char	*strim;

	ft_inittwovar(&i, &j);
	len = ft_strlen(s);
	while (s[len - 1] == c)
	{
		len--;
		if (len == 0)
			return (NULL);
	}
	while (s[i] == c)
	{
		len--;
		i++;
	}
	strim = ft_strnew(len);
	while (j != len)
	{
		strim[j] = s[i];
		ft_inctwovar(&i, &j);
	}
	return (strim);
}
