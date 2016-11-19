/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:17:16 by abureau           #+#    #+#             */
/*   Updated: 2016/11/19 20:18:02 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

int					get_len(const char *str, int base, int max)
{
	int	i;

	i = 0;
	while (ft_isalnum(str[i]) && i < max)
	{
		if (base > 10)
		{
			if (!((str[i] >= 'a' && str[i] < 'a' + base - 10)
						|| (str[i] >= 'A' && str[i] < 'A' + base - 10)
						|| ft_isdigit(str[i])))
				return (i);
		}
		else
		{
			if (!(ft_isdigit(str[i]) && str[i] < '0' + base))
				return (i);
		}
		i++;
	}
	return (i);
}
