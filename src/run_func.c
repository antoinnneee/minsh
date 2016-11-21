/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:52 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 13:37:41 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	init_cd(char **tmp, char ***old, t_msh **msh, int *state)
{
	char	**str;

	init_pwd(msh);
	str = get_env("HOME=", *msh);
	*state = 0;
	if (str)
		*state = 1;
	*tmp = (char*)ft_memalloc((sizeof(char) * 256));
	*tmp = getcwd(*tmp, 256);
	*old = get_env("OLDPWD=", *msh);
	set_env("PWD=", ft_strchr(**old, '=') + 1, msh);
	free(**old);
	**old = ft_memalloc((sizeof(char) * 256));
	**old = ft_strcpy(**old, "OLDPWD=");
	**old = ft_strcat(**old, *tmp);
}

void		run_cd(t_cmd *cmd, t_msh *msh)
{
	char	**old;
	char	*tmp;
	int		state;

	init_cd(&tmp, &old, &msh, &state);
	if (cmd->param && *cmd->param && cmd->param[0][0] == '~' && state)
		chdir(ft_strchr(*get_env("HOME=", msh), '=') + 1);
	else if (cmd->param && *cmd->param)
	{
		if (chdir(cmd->param[0]) == -1)
			printcd(cmd->param[0]);
	}
	else if (cmd->option && !(ft_strcmp(cmd->option[0], "-")))
	{
		chdir(ft_strchr(*get_env("PWD=", msh), '=') + 1);
		ft_putendl(ft_strchr(*get_env("PWD=", msh), '=') + 1);
	}
	else if (state)
		chdir(ft_strchr(*get_env("HOME=", msh), '=') + 1);
	else
		ft_putendl("env var manquante, use setenv HOME=[path]");
	tmp = getcwd(tmp, 256);
	set_env("PWD=", tmp, &msh);
	free(tmp);
}

void		run_unset(t_cmd *cmd, t_msh **msh)
{
	int	i;

	i = 0;
	if (cmd->param)
	{
		while ((*msh)->env[i])
		{
			if (beginby(cmd->param[0], (*msh)->env[i]))
			{
				unset_env(cmd->param[0], msh);
				return ;
			}
			i++;
		}
	}
}

void		run_pwd(void)
{
	char *re;

	re = ft_memalloc((sizeof(char) * 256));
	if (re)
	{
		re = getcwd(re, 256);
		ft_putendl(re);
		free(re);
	}
}

void		run_exit(t_cmd *cmd, t_msh *msh)
{
	if (cmd)
		free_cmd(cmd);
	if (msh)
		free_msh(&msh);
	free_path(0, 0);
	f(NULL, 1);
	fb(NULL, 1);
	exit(0);
}
