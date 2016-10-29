/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:25:36 by abureau           #+#    #+#             */
/*   Updated: 2016/01/13 13:30:21 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t len)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	if (len == 0)
		return (str);
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (s);
}
