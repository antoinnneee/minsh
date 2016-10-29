/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:36:46 by abureau           #+#    #+#             */
/*   Updated: 2015/12/04 13:18:15 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;

	tmp = (char*)dst;
	tmp2 = (char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if ((unsigned char)tmp2[i] == (unsigned char)c)
			return ((void*)&tmp[i + 1]);
		i++;
	}
	return (NULL);
}
