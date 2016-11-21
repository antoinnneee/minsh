/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:34:15 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 14:28:19 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

void		unset_env(char *name, t_msh **msh)
{
	int		i;
	int		j;
	char	**tmpenv;

	ft_inittwovar(&i, &j);
	tmpenv = (char**)ft_memalloc(sizeof(char*) * (FSS((*msh)->env, NULL)));
	while ((*msh)->env[i])
	{
		if (beginby(name, (*msh)->env[i]))
			i++;
		else
		{
			tmpenv[j] = ft_strdup((*msh)->env[i]);
			ft_inctwovar(&i, &j);
		}
	}
	i = 0;
	while ((*msh)->env[i])
	{
		free((*msh)->env[i]);
		i++;
	}
	free((*msh)->env);
	(*msh)->env = tmpenv;
}

static void	p_env_unset(void)
{
	ft_putendl("env: cannot specify --null (-0) with command");
	ft_putendl("try 'env --help' for more informqtion.");
}

void		env_param(t_cmd **cmd, t_msh ***msh, t_msh **tmp, int *opt)
{
	int		i;
	char	*value;
	char	*mpath;

	i = -1;
	while ((*cmd)->param[++i] && ft_strchr((*cmd)->param[i], '='))
	{
		value = ft_strdup(ft_strchr((*cmd)->param[i], '='));
		mpath = ft_strsub((*cmd)->param[i], 0, ft_strlen((*cmd)->param[i])
				- ft_strlen(value) + 1);
		set_env(mpath, &value[1], tmp);
		(value) ? free(value) : 1U;
		(mpath) ? free(mpath) : 1U;
	}
	if ((*cmd)->param[i] && *opt != 42)
	{
		*cmd = mod_cmd(cmd, i);
		reset_path(tmp);
		exec_cmd(cmd, *msh, tmp);
		reset_path(*msh);
		free_msh(tmp);
		*tmp = NULL;
	}
	else if (*opt != 42)
		print_msh(*tmp, *opt);
}

void		env_unset(t_cmd **cmd, t_msh **tmp, int *opt, t_msh **msh)
{
	int	i;

	i = -1;
	if ((*cmd)->param)
	{
		while ((*tmp)->env[++i])
			if (beginby((*cmd)->param[0], (*tmp)->env[i]))
				unset_env((*cmd)->param[0], tmp);
		if (*opt & (1U << 0) && (*cmd)->param[1])
			p_env_unset();
		else if ((*cmd)->param[1])
		{
			*cmd = mod_cmd(cmd, 1);
			exec_cmd(cmd, msh, tmp);
		}
		else
			print_msh((*tmp), *opt);
	}
	else
	{
		ft_putendl("env: option requires an argument '-u'");
		(tmp) ? free_msh(tmp) : 1U;
	}
}
