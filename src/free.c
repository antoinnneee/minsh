/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:27:11 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 17:36:58 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	ft_putendl("free_cmd");
	if (cmd)
	{
		if (cmd->prog)
			free(cmd->prog);
		if (cmd->param)
		{
			while (cmd->param[i])
				free(cmd->param[i++]);
			i = 0;
			free(cmd->param);
		}
		if (cmd->option)
		{
			while (cmd->option[i])
				free(cmd->option[i++]);
			i = 0;
			free(cmd->option);
		}
		free(cmd);
	}
	ft_putendl("free_cmd end");
}

void	free_msh(t_msh **tmp)
{
	int		i;
	t_msh	*msh;

	if (tmp)
		msh = *tmp;
	else
		return ;
	i = 0;
	if (msh)
	{
		if (msh->env)
		{
			while (msh->env[i])
			{
				free(msh->env[i]);
				msh->env[i] = NULL;
				i++;
			}
			free(msh->env);
			msh->env = NULL;
		}
		free(msh);
		msh = NULL;
	}
	*tmp = NULL;
}

void	free_split(char ***split)
{
	int	i;

	i = 0;
	if (*split)
	{
		while (*split[i])
		{
			free(*split[i]);
			*split[i] = NULL;
			i++;
		}
		free(*split);
	}
}

void	free_path(void)
{
	char	**path;
	int		i;

	i = 0;
	path = (char **)set_add_path(0, 0);
	if (path)
	{
		while (path[i])
		{
			free(path[i]);
			path[i] = NULL;
			i++;
		}
		free(path);
		path = NULL;
		set_add_path((t_u64)NULL, 0);
	}
}
