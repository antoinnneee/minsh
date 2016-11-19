/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:00:55 by abureau           #+#    #+#             */
/*   Updated: 2016/11/19 20:27:32 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static	void		echoption_b(char **option, int *opt, int i)
{
	if (isbegin("-n", option[i]))
		*opt = *opt | (1U << 0);
	else if (isbegin("-e", option[i]))
		*opt = *opt | (1U << 1);
	else if (isbegin("-E", option[i]))
		*opt = *opt | (1U << 2);
	else
		ft_putstr(option[i]);
}

unsigned int		echoption(char **option)
{
	int	i;
	int	opt;

	i = 0;
	opt = 0;
	if (option)
		while (option[i])
		{
			if (isbegin("--help", option[i]))
			{
				print_echo_h();
				opt = opt | (1U << 3);
				return (opt);
			}
			else if (isbegin("--version", option[i]))
			{
				print_echo_v();
				opt = opt | (1U << 3);
				return (opt);
			}
			else
				echoption_b(option, &opt, i);
			i++;
		}
	return (opt);
}

static void			printhexa(const char *str, int *i)
{
	int		len;
	char	*sub;

	if ((len = get_len(str, 16, 2)))
	{
		sub = ft_strsub(str, 0, len + 1);
		ft_putendl(sub);
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
		ft_putendl("sub :");
		ft_putendl(sub);
		ft_putendl(": sub");
		if (sub)
		{
			ft_putchar((char)ft_atoi_base(sub, 8));
			free(sub);
		}
		*i = *i + len + 1;
	}
	echoflag(WRITE, 0);
}

void				echoprint(const char *str, unsigned int opt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (echoflag(READ, STOP))
			return ;
		if (echoflag(READ, OCT))
		{
			printoct(&str[i], &i);
		}
		if (echoflag(READ, HEXA))
		{
			printhexa(&str[i], &i);
		}
		if ((opt & (1U << 1)))
			if (str[i] == '\\')
				echoprintchar(&str[++i]);
			else
				ft_putchar(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
