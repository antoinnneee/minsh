/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:05:38 by abureau           #+#    #+#             */
/*   Updated: 2016/01/13 14:06:45 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	i = 0;
	if (s1)
		i += i + ft_strlen(s1);
	if (s2)
		i += i + ft_strlen(s2);
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	if (s1)
		res = ft_strcat(res, s1);
	if (s2)
		res = ft_strcat(res, s2);
	return (res);
}
