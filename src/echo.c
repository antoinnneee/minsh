/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:00:55 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 13:48:04 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static void			printhexa(const char *str, int *i)
{
	int		len;
	char	*sub;

	if ((len = get_len(str, 16, 1)))
	{
		sub = ft_strsub(str, 0, len + 1);
		if (sub)
		{
			ft_putchar((char)ft_atoi_base(sub, 16));
			free(sub);
		}
		*i = *i + len + 1;
	}
	echoflag(WRITE, 0);
}

static void			printoct(const char *str, int *i)
{
	int		len;
	char	*sub;

	if ((len = get_len(str, 8, 2)))
	{
		sub = ft_strsub(str, 0, len + 1);
		if (sub)
		{
			ft_putchar((char)ft_atoi_base(sub, 8));
			free(sub);
		}
		*i = *i + len + 1;
	}
	echoflag(WRITE, 0);
}

static void			testflag(const char *str, int *i)
{
	if (echoflag(READ, OCT))
		printoct(&str[*i], i);
	if (echoflag(READ, HEXA))
		printhexa(&str[*i], i);
}

void				echoprint(const char *str, unsigned int opt)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (echoflag(READ, STOP))
			return ;
		testflag(str, &i);
		if (str[i] == '\\')
		{
			if ((opt & (1U << 1)))
				echoprintchar(&str[++i]);
			else
				ft_putchar(str[++i]);
		}
		else if (str[i] == '\'')
		{
			if (str[i + 1] == '\\')
				echoprintchar(&str[i = i + 2]);
			else
				ft_putchar(str[++i]);
		}
		else
			ft_putchar(str[i]);
	}
}
