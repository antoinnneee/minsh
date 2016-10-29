/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counteradd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:26:55 by abureau           #+#    #+#             */
/*   Updated: 2016/01/11 15:58:27 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_counter	ft_counteradd(t_counter cnt, int val, char c)
{
	if (c == '+')
	{
		cnt.value = cnt.value + val;
	}
	else
	{
		cnt.value = cnt.value - val;
	}
	cnt.ope = c;
	cnt.nbo = cnt.nbo + 1;
	cnt.num = cnt.num;
	return (cnt);
}
