/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countermod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:35:59 by abureau           #+#    #+#             */
/*   Updated: 2016/01/11 17:06:27 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	si(int *ct, const char *str)
{
	return (ft_atoi(ft_strsub(str, ct[2], ct[1] - 1)));
}

static void	movecdigit(const char *s, int *pos, int *tmp)
{
	*pos += 1;
	*tmp = *pos;
	while (ft_isdigit(s[*pos]))
		*pos += 1;
}

static void	ft_ifc(const char *s, int *value, int *pos, int *tmp)
{
	*pos = *pos + 1;
	*tmp = *pos;
	while (ft_isdigit(s[*pos]))
		*pos += 1;
	*value = ft_atoi(ft_strsub(s, *tmp, *pos - *tmp));
}

static void	coremodif(t_counter *cnt, int *c, const char *s, int i)
{
	while (s[c[1]])
	{
		if (s[c[1]] == 'c')
			ft_ifc(s, &c[0], &c[1], &c[2]);
		if (s[c[1]] == 'e')
		{
			movecdigit(s, &c[1], &c[2]);
			cnt[c[0]] = ft_countereq(cnt[c[0]], cnt[si(c, s)], s[c[2] - 1]);
			c[1] = c[1] - 1;
		}
		while (i >= 0)
		{
			if (s[c[1]] == cnt[0].func.carac[i])
			{
				movecdigit(s, &c[1], &c[2]);
				cnt[c[0]] = (cnt[0].func.functab[i])(cnt[c[0]],
														si(c, s), s[c[2] - 1]);
				c[1] = c[1] - 1;
			}
			i--;
		}
		i = 6;
		c[1] = c[1] + 1;
	}
}

t_counter	*ft_countermod(t_counter *cnt, const char *s)
{
	int		*c;
	int		i;

	i = 6;
	c = (int*)malloc(sizeof(int) * 3);
	ft_initthreevar(&c[0], &c[1], &c[2]);
	coremodif(cnt, c, s, i);
	free(c);
	return (cnt);
}
