/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:49:33 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 13:29:39 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

void			init_pwd(t_msh **msh)
{
	char	**tmp;
	char	*re;

	re = NULL;
	re = ft_memalloc((sizeof(char) * 256));
	if (re)
	{
		re = getcwd(re, 256);
		tmp = get_env("PWD=", *msh);
		if (!tmp)
			set_env("PWD=", re, msh);
		tmp = get_env("OLDPWD=", *msh);
		if (!tmp)
			set_env("OLDPWD=", re, msh);
		free(re);
	}
}

t_u64			set_add_path(t_u64 ptr, int state)
{
	static t_u64	data = 0;

	if (state == 1)
	{
		data = ptr;
	}
	else
		return (data);
	return (0);
}

t_u64			set_add_msh(t_u64 ptr, int state)
{
	static t_u64	data = 0;

	if (data == 0)
	{
		data = ptr;
	}
	else if (state == 1)
	{
		data = ptr;
	}
	else
		return (data);
	return (0);
}
