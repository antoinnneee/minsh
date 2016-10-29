/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:08:20 by abureau           #+#    #+#             */
/*   Updated: 2015/12/03 16:17:03 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (i > 0)
	{
		while (s != '\0')
		{
			if (*s == (char)c)
				return ((char *)s);
			if (i == 0)
				return (NULL);
			i--;
			s++;
		}
	}
	return (NULL);
}
