/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_getenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:13:04 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 13:17:16 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

char		*f_getenv(const char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (beginby(str, env[i]))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char		**get_env(char *name, t_msh *msh)
{
	int	i;

	i = 0;
	if (msh->env)
		while (msh->env[i])
		{
			if (!ft_strncmp(msh->env[i], name, ft_strlen(name)))
			{
				return (&msh->env[i]);
			}
			i++;
		}
	return (NULL);
}

static int	cnt_env(t_msh *msh)
{
	int	i;

	i = 0;
	if (msh->env)
		while (msh->env[i])
		{
			i++;
		}
	return (i);
}

void		add_env(char *name, char *value, t_msh **msh)
{
	int		i;
	char	**tmpenv;

	i = 0;
	tmpenv = (char**)ft_memalloc(sizeof(char*) * (cnt_env(*msh) + 2));
	if ((*msh)->env)
		while ((*msh)->env[i])
		{
			tmpenv[i] = ft_strdup((*msh)->env[i]);
			i++;
		}
	tmpenv[i] = (char*)ft_memalloc((sizeof(char) *
				(ft_strlen(name) + ft_strlen(value) + 1)));
	tmpenv[i] = ft_strcpy(tmpenv[i], name);
	tmpenv[i] = ft_strcat(tmpenv[i], value);
	tmpenv[i + 1] = NULL;
	i = 0;
	if ((*msh)->env)
	{
		while ((*msh)->env[i])
			free((*msh)->env[i++]);
		free((*msh)->env);
	}
	(*msh)->env = tmpenv;
}

void		set_env(char *name, char *value, t_msh **msh)
{
	char	**old;

	old = get_env(name, *msh);
	if (old)
	{
		free(*old);
		*old = (char*)ft_memalloc((sizeof(char)
					* (ft_strlen(name) + ft_strlen(value) + 1)));
		*old = ft_strcpy(*old, name);
		*old = ft_strcat(*old, value);
	}
	else
	{
		add_env(name, value, msh);
	}
}
