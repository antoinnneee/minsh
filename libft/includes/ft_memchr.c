/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:54:53 by abureau           #+#    #+#             */
/*   Updated: 2015/12/01 13:16:13 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (n != i)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			return ((void*)&(tmp[i]));
		i++;
	}
	return (NULL);
}
