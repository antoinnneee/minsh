/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:21:00 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 12:06:24 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

int					echoflag(unsigned int state, int val)
{
	static int st_val = 0;

	if (state == WRITE)
	{
		if (val == 0)
			st_val = 0;
		else
			st_val = st_val | val;
		return (0);
	}
	else if (state == READ)
	{
		if (st_val & val)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static void			echoprintchar_b(const char *c)
{
	if (*c == 't')
		ft_putchar(9);
	else if (*c == 'v')
		ft_putchar(11);
	else if (*c == '0')
		echoflag(WRITE, OCT);
	else if (*c == 'x')
		echoflag(WRITE, HEXA);
	else
	{
		ft_putchar(*c);
	}
}

void				echoprintchar(const char *c)
{
	if (*c == '\\')
		ft_putchar('\\');
	else if (*c == 'a')
		ft_putchar(7);
	else if (*c == 'b')
		ft_putchar(8);
	else if (*c == 'c')
		echoflag(WRITE, STOP);
	else if (*c == 'e')
		ft_putchar(27);
	else if (*c == 'f')
		ft_putchar(12);
	else if (*c == 'n')
		ft_putchar('\n');
	else if (*c == 'r')
		ft_putchar(13);
	else
		echoprintchar_b(c);
}

void				run_echo(t_cmd *cmd, t_msh *msh)
{
	int				i;
	unsigned int	opt;

	opt = echoption(cmd->option);
	*msh = *msh;
	i = 0;
	if (cmd->param)
	{
		while (cmd->param[i])
		{
			echoprint(cmd->param[i], opt);
			if (echoflag(READ, STOP))
			{
				echoflag(WRITE, 0);
				return ;
			}
			ft_putchar(' ');
			i++;
		}
	}
	if (!(opt & (1U << 0)))
		ft_putchar('\n');
}
