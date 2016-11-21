/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:31:41 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 13:47:38 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

void				print_echo_v(void)
{
	ft_putendl("echo version : 1.0");
}

void				print_echo_h(void)
{
	ft_putendl("\techo [SHORT-OPTION] [STRING]");
	ft_putendl("\techo [LONG-OPTION]\n");
	ft_putendl("\tEcho the STRING(s) to standard output.\n");
	ft_putendl("\t-n\tdo not output the trailing newline");
	ft_putendl("\t-e\tenable interpretation of backslash escapes");
	ft_putendl("\t-E\tdisable interpretation of backslash escapes (default)");
	ft_putendl("\t--help\tdisplay this help and exit");
	ft_putendl("\t--version\n\t\toutput version information and exit\n");
	ft_putstr("\tIf -e is in effect, the following, the following ");
	ft_putendl("sequences are recognized");
	ft_putendl("\t\\\\\tbackslash");
	ft_putendl("\t\\a\talert (BEL)");
	ft_putendl("\t\\b\tbackspace");
	ft_putendl("\t\\c\tproduce no further output");
	ft_putendl("\t\\e\tescape");
	ft_putendl("\t\\f\tform feed");
	ft_putendl("\t\\n\tnew line");
	ft_putendl("\t\\r\tcarriage return");
	ft_putendl("\t\\t\thorizontal tab");
	ft_putendl("\t\\v\tvertical tab");
	ft_putendl("\t\\0NNN\tbyte with octal vqlue NNN (1 to 3 digits)");
	ft_putendl("\t\\xHH\tbyte with octal vqlue NNN (1 to 3 digits)");
}

static void			echoption_b(char **option, int *opt, int i)
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
