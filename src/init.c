/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:25:06 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 18:10:31 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "../includes/minishell.h"

char			**copy_path(char **env)
{
	char	**path;
	char	*tmp;

	tmp = NULL;
	if ((tmp = f_getenv("PATH", env)))
	{
		path = ft_strsplit(&tmp[ft_strlen("PATH=")], ':');
		return (path);
	}
	else
		return (NULL);
}

void			p_exit(const char *str, int value)
{
	ft_putendl(str);
	exit(value);
}

t_msh			*copy_env(char **environ)
{
	int		i;
	int		j;
	t_msh	*msh;

	i = ft_strlensquare(environ, &j);
	if (ft_strlensquare(environ, NULL) == 0)
		p_exit("No env, exitting ...", 0);
	msh = (t_msh*)ft_memalloc(sizeof(t_msh));
	ft_bzero(msh, sizeof(t_msh));
	msh->env = (char**)ft_memalloc(sizeof(char*) * (FSS(environ, &i) + 1));
	while (environ[i])
	{
		msh->env[i] = (char*)ft_memalloc(sizeof(char)
												* (ft_strlen(environ[i]) + 1));
		while (environ[i][j])
		{
			msh->env[i][j] = environ[i][j];
			j++;
		}
		msh->env[i][j] = '\0';
		j = 0;
		i++;
	}
	msh->env[i] = NULL;
	return (msh);
}

static void		core_split(t_cmd **cmd, char *commande, int i, int nb)
{
	char	*tmp;

	(*cmd)->prog = ft_strsub(commande, 0, i);
	tmp = get_option(&commande[i], &nb);
	if (tmp)
	{
		(*cmd)->option = ft_strsplit(tmp, ':');
		free(tmp);
		tmp = NULL;
	}
	i = i + nb - 1;
	nb = i;
	if (commande[i])
		tmp = get_param(&commande[i], &nb);
	if (tmp)
	{
		(*cmd)->param = ft_strsplit(tmp, ':');
		free(tmp);
		tmp = NULL;
	}
	if (commande)
		free(commande);
}

t_cmd			*split_cmd(char *commande)
{
	t_cmd	*cmd;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	if (!cmd)
		p_exit("malloc error", 0);
	while (commande[i])
	{
		if (commande[i] == ' ')
		{
			core_split(&cmd, commande, i, nb);
			return (cmd);
		}
		i++;
	}
	cmd->prog = ft_strdup(commande);
	cmd->param = NULL;
	free(commande);
	return (cmd);
}
