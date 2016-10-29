/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:18:48 by abureau           #+#    #+#             */
/*   Updated: 2016/09/12 19:16:51 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_return(int i, int p, int state)
{
	if (state > 1)
		return (0);
	else if (state == 1)
		if (!p)
			return (-i);
	return (i);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		state;
	int		p;
	char	*str;

	ft_initthreevar(&i, &p, &state);
	str = ft_strdup(s);
	if (str)
	{
		while ((*str > 0x00) && (*str <= 0x20))
		{
			str++;
		}
		if (*str == '+' || *str == '-')
		{
			if (*str == '+')
				p = 1;
			state++;
			str++;
		}
		while (*str != '\0' && ft_isdigit(*str))
			i = i * 10 + *str++ - '0';
		i = ft_return(i, p, state);
	}
	return (i);
}
