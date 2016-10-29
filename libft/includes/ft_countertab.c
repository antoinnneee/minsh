/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countertab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:27:40 by abureau           #+#    #+#             */
/*   Updated: 2016/01/11 17:38:07 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_counter	*ft_countertab(const char *str)
{
	int			i;
	t_counter	*tab;
	int			nb;

	i = ft_atoi(str);
	tab = (t_counter*)malloc(sizeof(t_counter) * i);
	nb = i;
	while (i)
	{
		i--;
		tab[i] = ft_counterinit(nb, i);
	}
	return (tab);
}
