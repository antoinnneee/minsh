/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:49:37 by abureau           #+#    #+#             */
/*   Updated: 2015/12/03 15:13:14 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
