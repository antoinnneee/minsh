/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:41:42 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 13:01:25 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static int		exec_builtin(t_cmd **cmd, t_msh **msh)
{
	if (!ft_strcmp((*cmd)->prog, "echo"))
		run_echo(*cmd, *msh);
	else if (!ft_strcmp((*cmd)->prog, "cd"))
		run_cd(*cmd, *msh);
	else if (!ft_strcmp((*cmd)->prog, "pwd"))
		run_pwd();
	else if (!ft_strcmp((*cmd)->prog, "setenv"))
		run_setenv(*cmd, msh);
	else if (!ft_strcmp((*cmd)->prog, "unsetenv"))
		run_unset(*cmd, msh);
	else if (!ft_strcmp((*cmd)->prog, "env"))
		run_env(cmd, msh);
	else if (!ft_strcmp((*cmd)->prog, "exit") || !ft_strcmp((*cmd)->prog, "q"))
		run_exit(*cmd, *msh);
	else
		return (0);
	return (1);
}

void			exec_cmd(t_cmd **cmd, t_msh **msh, t_msh **nmsh)
{
	if (!nmsh)
	{
		if (!exec_builtin(cmd, msh))
		{
			execute((*cmd)->prog, *cmd, msh, NULL);
		}
	}
	else
	{
		if (!exec_builtin(cmd, nmsh))
		{
			execute((*cmd)->prog, *cmd, msh, nmsh);
		}
	}
}

char			*get_option(char *cmd, int *i)
{
	int		j;
	char	*option;
	int		ind;

	ind = 0;
	option = NULL;
	while ((cmd[ind] == ' ' || cmd[ind] == '"') && cmd[ind])
	{
		ind++;
		if (cmd[ind] == '-')
		{
			j = ind;
			ind++;
			while (ft_isalnum(cmd[ind]) || cmd[ind] == '-' || cmd[ind] == '=')
				ind = ind + 1;
			if (!option)
				option = ft_strsub(cmd, j, ind - j);
			else
				option = secure_cat(
					secure_cat(option, ":", 0), ft_strsub(cmd, j, ind - j), 1);
		}
	}
	*i = ind + 1;
	return (option);
}
