/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterrecap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:38:28 by abureau           #+#    #+#             */
/*   Updated: 2016/01/11 17:44:00 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_counterrecap(t_counter *cnt)
{
	int i;

	i = 0;
	ft_putstrnb("NUMBER OF VAR : ", cnt[0].num);
	while (i < cnt[0].num)
	{
		ft_putchar('\n');
		ft_putstrnb("Check var numero : ", i);
		ft_putstrnb("Check value      : ", cnt[i].value);
		ft_putstr("Check last ope   : ");
		ft_putchar(cnt[i].ope);
		ft_putchar('\n');
		ft_putstrnb("Check number of ope : ", cnt[i].nbo);
		i++;
	}
}
