/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:17 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 12:55:37 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int					ft_strlensquare(char **env, int *init)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			i++;
		}
		i++;
	}
	if (init)
		*init = 0;
	return (i);
}

void				reset_path(t_msh **msh)
{
	free_path();
	set_add_path((t_u64)copy_path((*msh)->env), 1);
}

void				run_setenv(t_cmd *cmd, t_msh **msh)
{
	int		i;

	i = 42;
	if (cmd->param)
	{
		core_setenv(&cmd, &msh, i);
		if (isbegin("PATH=", cmd->param[0]))
		{
			reset_path(msh);
		}
	}
}
