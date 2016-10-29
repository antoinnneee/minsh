/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countereq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:26:15 by abureau           #+#    #+#             */
/*   Updated: 2016/01/11 15:58:59 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_counter	ft_countereq(t_counter cnt1, t_counter cnt2, char c)
{
	cnt1.value = cnt2.value;
	cnt1.ope = c;
	cnt1.nbo = cnt1.nbo + 1;
	cnt1.num = cnt1.num;
	return (cnt1);
}
