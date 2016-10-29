/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:07:27 by abureau           #+#    #+#             */
/*   Updated: 2016/01/13 14:05:30 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = NULL;
	if (s && f)
	{
		tmp = ft_strnew(ft_strlen(s));
		if (!tmp)
			return (NULL);
		while (s[i])
		{
			tmp[i] = f(i, s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
