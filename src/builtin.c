/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:17 by abureau           #+#    #+#             */
/*   Updated: 2016/11/19 19:58:38 by abureau          ###   ########.fr       */
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

void				run_setenv(t_cmd *cmd, t_msh **msh)
{
	int		i;

	i = 42;
	if (cmd->param)
	{
		core_setenv(&cmd, &msh, i);
	}
}
