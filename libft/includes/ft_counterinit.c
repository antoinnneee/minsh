/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:27:58 by abureau           #+#    #+#             */
/*   Updated: 2016/01/11 16:09:06 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_counter		ft_counterinit(int nb, int i)
{
	t_counter	cnt;
	t_functable	funclist;

	if (i == 0)
	{
		funclist = ft_counterinitfunc();
		cnt.func = funclist;
	}
	cnt.value = 0;
	cnt.ope = 'i';
	cnt.nbo = 0;
	cnt.num = nb;
	return (cnt);
}
