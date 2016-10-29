/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:35:58 by abureau           #+#    #+#             */
/*   Updated: 2015/12/04 13:21:55 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	lens;

	lens = ft_strlen(s) + 1;
	if (c == 0)
		return ((char *)&s[lens] - 1);
	while (lens >= 0)
	{
		if (s[lens] == (char)c)
		{
			return ((char *)&s[lens]);
		}
		lens--;
	}
	return (NULL);
}
