/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:54:16 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 12:17:27 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static t_msh		*cpy_env(t_msh *msh)
{
	t_msh	*tmp;
	int		cnt;
	int		i;

	cnt = ft_strlensquare(msh->env, &i);
	tmp = (t_msh*)ft_memalloc(sizeof(t_msh));
	if (!tmp)
		return (NULL);
	tmp->env = (char**)ft_memalloc(sizeof(char*) * (cnt + 1));
	if (msh->env)
		while (msh->env[i])
		{
			tmp->env[i] = ft_strdup(msh->env[i]);
			i++;
		}
	return (tmp);
}

static t_msh		*pandfree(t_msh ***tmp, int value, char *str)
{
	if (value == 1)
	{
		print_env_v();
		if (*tmp)
			free_msh(*tmp);
	}
	else if (value == 0)
	{
		print_env_help();
		if (*tmp)
			free_msh(*tmp);
	}
	else if (value == 2)
	{
		if (*tmp)
			free_msh(*tmp);
	}
	else
	{
		ft_putstr("invalid option :");
		ft_putendl(str);
		if (*tmp)
			free_msh(*tmp);
	}
	return (NULL);
}

static t_msh		*opt_env(t_msh **tmp, t_cmd **cmd, int *opt, int *i)
{
	while ((*cmd)->option[*i])
	{
		if (isbegin("-0", (*cmd)->option[*i]) ||
				isbegin("--null", (*cmd)->option[*i]))
			*opt = *opt | (1U << 0);
		else if (isbegin("--unset=", (*cmd)->option[*i]))
			unset_env(&(*cmd)->option[*i][ft_strlen("--unset=")], tmp);
		else if (isbegin("-u", (*cmd)->option[*i]))
			*opt = *opt | (1U << 1);
		else if (isbegin("-i", (*cmd)->option[*i]) ||
				!(ft_strcmp("-", (*cmd)->option[*i])))
			*tmp = pandfree(&tmp, 2, NULL);
		else if (isbegin("-v", (*cmd)->option[*i]) ||
				isbegin("--version", (*cmd)->option[*i]))
			return (pandfree(&tmp, 1, NULL));
		else if (isbegin("-h", (*cmd)->option[*i]) ||
				isbegin("--help", (*cmd)->option[*i]))
			return (pandfree(&tmp, 0, NULL));
		else
		{
			return (pandfree(&tmp, 42, (*cmd)->option[*i]));
		}
		*i = *i + 1;
	}
	return (*tmp);
}

void				run_env(t_cmd **cmd, t_msh **msh)
{
	int		i;
	t_msh	*tmp;
	int		opt;

	opt = 0;
	if (!msh || !*msh)
		return ;
	tmp = cpy_env(*msh);
	i = 0;
	if ((*cmd)->option)
		tmp = opt_env(&tmp, cmd, &opt, &i);
	if (opt & (1U << 1))
		env_unset(cmd, &tmp, &opt, msh);
	else
	{
		if (!tmp)
			tmp = new_msh();
		if ((*cmd)->param)
			env_param(cmd, &msh, &tmp, &opt);
		else if (!(*cmd)->param)
			print_msh(tmp, opt);
		if (tmp)
			free_msh(&tmp);
	}
}
