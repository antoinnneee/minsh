/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:59:51 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 13:59:16 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void			p_exec_error(char *name, char *prog, int state)
{
	if (state == 0)
	{
		if (prog[0] == '.')
		{
			ft_putstr("minsh: ");
			ft_putstr(name);
			if (access(name, F_OK))
				ft_putendl(": No such file or directory");
			else
				ft_putendl(": Permission denied");
		}
		else
		{
			ft_putstr(name);
			ft_putendl(": command not found");
		}
	}
	else if (state == 2)
	{
		ft_putstr("minsh: ");
		ft_putstr(name);
		ft_putendl(": is a Directory");
	}
}

void			printcd(char *str)
{
	ft_putstr("cd : ");
	ft_putstr(str);
	ft_putstr(" : no such file or directory\n");
}

void			printenv(char **env)
{
	int i;

	i = 0;
	ft_putendl("============== PRINT ENV =============");
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void			print_detail_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	ft_putstr("programme : ");
	if (cmd->prog)
		ft_putstr(cmd->prog);
	if (cmd->param)
	{
		ft_putstr("\nparam : ");
		while (cmd->param[i])
			ft_putendl(cmd->param[i++]);
		i = 0;
	}
	if (cmd->option)
	{
		ft_putstr("\noption : ");
		while (cmd->option[i])
			ft_putendl(cmd->option[i++]);
	}
	else
		ft_putchar('\n');
}
