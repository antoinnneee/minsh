/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:33:41 by abureau           #+#    #+#             */
/*   Updated: 2016/01/13 15:48:49 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpdest;
	char	*tmpsrc;
	size_t	i;

	i = 0;
	tmpsrc = (char*)src;
	tmpdest = (char*)dst;
	if (tmpdest > tmpsrc)
	{
		tmpdest += len;
		tmpsrc += len;
		while (i < len)
		{
			*--tmpdest = *--tmpsrc;
			i++;
		}
	}
	else
		while (i < len)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	return (tmpdest);
}
